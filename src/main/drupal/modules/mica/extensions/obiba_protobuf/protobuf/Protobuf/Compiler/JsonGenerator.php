<?php

namespace DrSlump\Protobuf\Compiler;

use DrSlump\Protobuf;
use google\protobuf as proto;

class JsonGenerator extends AbstractGenerator {
  /**
   * Get an option from the compiler arguments or from the proto file.
   *
   * @param string $name
   * @return string|null
   */
  protected function getOption($name) {
    $opt = $this->compiler->getOption($name);

    if (NULL === $opt) {
      $opts = $this->proto->getOptions();
      if (!empty($opts) && isset($opts['json.' . $name])) {
        $opt = $opts['json.' . $name];
      }
    }

    return $opt;
  }


  public function getNamespace(proto\FileDescriptorProto $proto = NULL) {
    $proto = $proto ? : $this->proto;

    $opts = $proto->getOptions();
    if ($this->compiler->getOption('namespace')) {
      $namespace = $this->compiler->getOption('namespace');
    }
    else if (isset($opts['json.namespace'])) {
      $namespace = $opts['json.namespace'];
    }
    else if (isset($opts['json.package'])) {
      $namespace = $opts['json.package'];
    }
    else {
      $namespace = parent::getNamespace($proto);
    }

    $namespace = trim($namespace, '.');
    return $namespace;
  }


  public function generate(proto\FileDescriptorProto $proto) {
    parent::generate($proto);

  }

  protected function buildFile(proto\FileDescriptorProto $proto, $fname, $contents) {
    $suffix = $this->getOption('suffix') ? : '.js';
    $fname .= $suffix;

    $file = new \google\protobuf\compiler\CodeGeneratorResponse\File();
    $file->setName($fname);

    $s = array();
    $s[] = "// DO NOT EDIT! Generated by Protobuf-PHP protoc plugin " . Protobuf::VERSION;
    $s[] = "// Source: " . $proto->getName();
    $s[] = "//   Date: " . gmdate('Y-m-d H:i:s');
    $s[] = "";
    $s[] = "// @@protoc_insertion_point(scope_file)";
    $s[] = "";
    $s[] = "(function(){";
    $s[] = "";
    $s[] = "  /** @namespace */";
    $s[] = "  var $namespace = $namespace || {};";
    $s[] = "";
    $s[] = "  // Make it CommonJS compatible";
    $s[] = "  if (typeof exports !== 'undefined') {";
    $s[] = "    var ProtoJson = this.ProtoJson;";
    $s[] = "    if (!ProtoJson && typeof require !== 'undefined') {";
    $s[] = "      ProtoJson = require('ProtoJson');";
    $s[] = "    }";
    $s[] = "    $namespace = exports;";
    $s[] = "  } else {";
    $s[] = "    this.$namespace = $namespace;";
    $s[] = "  }";
    $s[] = "";
    $s[] = $contents;
    $s[] = "";
    $s[] = "})();";
    $s[] = "";

    $contents = implode(PHP_EOL, $s) . PHP_EOL . $contents;
    $file->setContent($contents);
    return $file;
  }

  public function compileProtoFile(proto\FileDescriptorProto $proto) {
    $file = new \google\protobuf\compiler\CodeGeneratorResponse\File();

    $opts = $proto->getOptions();
    $name = pathinfo($proto->getName(), PATHINFO_FILENAME);
    $name .= isset($opts['json.suffix'])
      ? $opts['json.suffix']
      : '.js';
    $file->setName($name);

    $namespace = $this->getNamespace($proto);

    $s[] = "// DO NOT EDIT! Generated by Protobuf for PHP protoc plugin " . Protobuf::VERSION;
    $s[] = "// Source: " . $proto->getName();
    $s[] = "//   Date: " . date('Y-m-d H:i:s');
    $s[] = "";

    $s[] = "(function(){";
    $s[] = "/** @namespace */";
    $s[] = "var $namespace = $namespace || {};";
    $s[] = "";
    $s[] = "// Make it CommonJS compatible";
    $s[] = "if (typeof exports !== 'undefined') {";
    $s[] = "  var ProtoJson = this.ProtoJson;";
    $s[] = "  if (!ProtoJson && typeof require !== 'undefined')";
    $s[] = "    ProtoJson = require('ProtoJson');";
    $s[] = "  $namespace = exports;";
    $s[] = "} else {";
    $s[] = "  this.$namespace = $namespace;";
    $s[] = "}";
    $s[] = "";

    // Generate Enums
    foreach ($proto->getEnumTypeList() as $enum) {
      $s[] = $this->compileEnum($enum, $namespace);
    }

    // Generate Messages
    foreach ($proto->getMessageTypeList() as $msg) {
      $s[] = $this->compileMessage($msg, $namespace);
    }

    // Collect extensions
    if ($proto->hasExtension()) {
      foreach ($proto->getExtensionList() as $field) {
        $this->extensions[$field->getExtendee()][] = array($namespace, $field);
      }
    }

    // Dump all extensions found in this proto file
    if (count($this->extensions)) {
      foreach ($this->extensions as $extendee => $fields) {
        foreach ($fields as $pair) {
          list($ns, $field) = $pair;
          $s[] = $this->compileExtension($field, $ns, '');
        }
      }
    }

    $s[] = "})();";

    $src = implode("\n", $s);
    $file->setContent($src);
    return array($file);
  }

  public function compileEnum(proto\EnumDescriptorProto $enum, $namespace) {
    $s[] = "$namespace.$enum->name = {";
    $lines = array();
    foreach ($enum->getValueList() as $value) {
      $lines[] = "  /** @const */ $value->name: $value->number";
    }
    $s[] = implode(",\n", $lines);
    $s[] = '};';
    $s[] = '';
    return implode("\n", $s);
  }

  public function compileExtension(proto\FieldDescriptorProto $field, $ns, $indent) {
    $extendee = $this->normalizeReference($field->getExtendee());
    $name = $field->getName();
    if ($ns) {
      $name = $ns . '.' . $name;
    }
    $field->setName($name);

    $s[] = "ProtoJson.extend($extendee, {";
    $s[] = "  $field->number: " . $this->generateField($field);
    $s[] = "});";
    $s[] = '';

    return $indent . implode("\n$indent", $s);
  }

  public function compileMessage(proto\DescriptorProto $msg, $namespace) {
    $s[] = "/**";
    $s[] = " * @constructor";
    $s[] = " * @augments {ProtoJson.Message}";
    $s[] = " * @extends ProtoJson.Message";
    $s[] = " * @memberOf $namespace";
    $s[] = " * @param {object} data - Optional, provide initial data to parse";
    $s[] = " */";
    $s[] = "$namespace.$msg->name = ProtoJson.create({";
    $s[] = "  fields: {";

    $lines = array();
    foreach ($msg->getFieldList() as $field) {
      $lines[] = "    $field->number: " . $this->generateField($field);
    }
    $s[] = implode(",\n", $lines);

    $s[] = "  },";
    $s[] = "  ranges: [";
    // @todo dump extension ranges
    $s[] = "  ]";
    $s[] = "});";
    $s[] = "";

    // Compute a new namespace with the message name as suffix
    $namespace .= "." . $msg->getName();

    // Generate getters/setters
    foreach ($msg->getFieldList() as $field) {
      $s[] = $this->generateAccessors($field, $namespace);
    }

    // Generate Enums
    foreach ($msg->getEnumTypeList() as $enum):
      $s[] = $this->compileEnum($enum, $namespace);
    endforeach;

    // Generate nested messages
    foreach ($msg->getNestedTypeList() as $msg):
      $s[] = $this->compileMessage($msg, $namespace);
    endforeach;

    // Collect extensions
    foreach ($msg->getExtensionList() as $field) {
      $this->extensions[$field->getExtendee()][] = array($namespace, $field);
    }

    return implode("\n", $s);
  }


  public function generateField(proto\FieldDescriptorProto $field) {
    $reference = 'null';
    if ($field->hasTypeName()) {
      $reference = $field->getTypeName();
      if (substr($reference, 0, 1) !== '.') {
        throw new \RuntimeException('Only fully qualified names are supported: ' . $reference);
      }
      $reference = "'" . $this->normalizeNS($reference) . "'";
    }

    $default = 'null';
    if ($field->hasDefaultValue()):
      switch ($field->getType()) {
        case Protobuf::TYPE_BOOL:
          $default = $field->getDefaultValue() ? 'true' : 'false';
          break;
        case Protobuf::TYPE_STRING:
          $default = '"' . addcslashes($field->getDefaultValue(), '"\\') . '"';
          break;
        case Protobuf::TYPE_ENUM:
          $default = $this->normalizeNS($field->getTypeName()) . '.' . $field->getDefaultValue();
          break;
        default: // Numbers
          $default = $field->getDefaultValue();
      }
    endif;

    $data = array(
      "'" . $field->getName() . "'",
      $field->getLabel(),
      $field->getType(),
      $reference,
      $default,
      '{}'
    );

    return '[' . implode(', ', $data) . ']';
  }

  public function generateAccessors($field, $namespace) {
    $camel = $this->compiler->camelize(ucfirst($field->getName()));

    $s[] = "/**";
    $s[] = " * Check <$field->name> value";
    $s[] = " * @return {Boolean}";
    $s[] = " */";
    $s[] = "$namespace.prototype.has$camel = function(){";
    $s[] = "  return this._has($field->number);";
    $s[] = "};";
    $s[] = "";

    $s[] = "/**";
    $s[] = " * Set a value for <$field->name>";
    $s[] = " * @param {" . $this->getJsDoc($field) . "} value";
    $s[] = " * @return {" . $namespace . "}";
    $s[] = " */";
    $s[] = "$namespace.prototype.set$camel = function(value){";
    $s[] = "  return this._set($field->number, value);";
    $s[] = "};";
    $s[] = "";

    $s[] = "/**";
    $s[] = " * Clear the value of <$field->name>";
    $s[] = " * @return {" . $namespace . "}";
    $s[] = " */";
    $s[] = "$namespace.prototype.clear$camel = function(){";
    $s[] = "  return this._clear($field->number);";
    $s[] = "};";
    $s[] = "";

    if ($field->getLabel() !== Protobuf::RULE_REPEATED):

      $s[] = "/**";
      $s[] = " * Get <$field->name> value";
      $s[] = " * @return {" . $this->getJsDoc($field) . "}";
      $s[] = " */";
      $s[] = "$namespace.prototype.get$camel = function(){";
      $s[] = "  return this._get($field->number);";
      $s[] = "};";
      $s[] = "";

    else:

      $s[] = "/**";
      $s[] = " * Get an item from <$field->name>";
      $s[] = " * @param {int} idx";
      $s[] = " * @return {" . $this->getJsDoc($field) . "}";
      $s[] = " */";
      $s[] = "$namespace.prototype.get$camel = function(idx){";
      $s[] = "  return this._get($field->number, idx);";
      $s[] = "};";
      $s[] = "";

      $s[] = "/**";
      $s[] = " * Get <$field->name> value";
      $s[] = " * @return {" . $this->getJsDoc($field) . "[]}";
      $s[] = " */";
      $s[] = "$namespace.prototype.get{$camel}List = function(){";
      $s[] = "  return this._get($field->number);";
      $s[] = "};";
      $s[] = "";

      $s[] = "/**";
      $s[] = " * Add a value to <$field->name>";
      $s[] = " * @param {" . $this->getJsDoc($field) . "} value";
      $s[] = " * @return {" . $namespace . "}";
      $s[] = " */";
      $s[] = "$namespace.prototype.add$camel = function(value){";
      $s[] = "  return this._add($field->number, value);";
      $s[] = "};";
      $s[] = "";

    endif;

    return implode("\n", $s);
  }

  public function getJsDoc(proto\FieldDescriptorProto $field) {
    switch ($field->getType()) {
      case Protobuf::TYPE_DOUBLE:
      case Protobuf::TYPE_FLOAT:
        return 'Float';
      case Protobuf::TYPE_INT64:
      case Protobuf::TYPE_UINT64:
      case Protobuf::TYPE_INT32:
      case Protobuf::TYPE_FIXED64:
      case Protobuf::TYPE_FIXED32:
      case Protobuf::TYPE_UINT32:
      case Protobuf::TYPE_SFIXED32:
      case Protobuf::TYPE_SFIXED64:
      case Protobuf::TYPE_SINT32:
      case Protobuf::TYPE_SINT64:
        return 'Int';
      case Protobuf::TYPE_BOOL:
        return 'Boolean';
      case Protobuf::TYPE_STRING:
        return 'String';
      case Protobuf::TYPE_MESSAGE:
        return $this->normalizeNS($field->getTypeName());
      case Protobuf::TYPE_BYTES:
        return 'String';
      case Protobuf::TYPE_ENUM:
        return 'Int (' . $this->normalizeNS($field->getTypeName()) . ')';

      case Protobuf::TYPE_GROUP:
      default:
        return 'unknown';
    }
  }


  protected function normalizeNS($package) {
    // Remove leading dot (used in references)
    $package = ltrim($package, '.');

    if ($this->compiler->hasPackage($package)) {
      return $this->compiler->getPackage($package);
    }

    // Check the currently registered packages to find a root one
    $found = NULL;
    foreach ($this->compiler->getPackages() as $pkg => $ns) {
      // Keep only the longest match
      if (0 === strpos($package, $pkg . '.') && strlen($found) < strlen($pkg)) {
        $found = $pkg;
      }
    }

    // If no matching package was found issue a warning and use the package name
    if (!$found) {
      $this->compiler->warning('Non tracked package name found "' . $package . '"');
      $namespace = $package;
    }
    else {
      // Complete the namespace with the remaining package
      $namespace = $this->compiler->getPackage($found);
      $namespace .= substr($package, strlen($found));
      // Set the newly found namespace in the registry
      $this->compiler->setPackage($package, $namespace);
    }

    return $namespace;
  }
}