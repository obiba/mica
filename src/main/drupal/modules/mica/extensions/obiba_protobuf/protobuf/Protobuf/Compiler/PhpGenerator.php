<?php

namespace DrSlump\Protobuf\Compiler;

use DrSlump\Protobuf;
use google\protobuf as proto;

class PhpGenerator extends AbstractGenerator {
  protected $components = array();

  protected function addComponent($ns, $name, $src) {
    if (NULL !== $ns) {
      $name = $this->normalizeNS($ns . '.' . $name);
    }
    $this->components[$name] = $src;
  }

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
      if (!empty($opts) && isset($opts['php.' . $name])) {
        $opt = $opts['php.' . $name];
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
    else if ($this->compiler->getOption('package')) {
      $namespace = $this->compiler->getOption('package');
    }
    else if (isset($opts['php.namespace'])) {
      $namespace = $opts['php.namespace'];
    }
    else {
      $namespace = parent::getNamespace($proto);
    }

    $namespace = trim($namespace, '.\\');
    return str_replace('.', '\\', $namespace);
  }

  public function generate(proto\FileDescriptorProto $proto) {
    parent::generate($proto);

    $this->components = array();
    $namespace = $proto->getPackage();

    // Generate Enums
    foreach ($proto->getEnumType() as $enum) {
      $src = $this->compileEnum($enum, $namespace);
      $this->addComponent($namespace, $enum->getName(), $src);
    }

    // Generate Messages
    foreach ($proto->getMessageType() as $msg) {
      $src = $this->compileMessage($msg, $namespace);
      $this->addComponent($namespace, $msg->getName(), $src);
    }

    // Generate services
    if ($this->getOption('generic_services') && count($proto->hasService())):
      foreach ($proto->getServiceList() as $service) {
        $src = $this->compileService($service, $namespace);
        $this->addComponent($namespace, $service->getName(), $src);
      }
    endif;

    // Collect extensions
    if ($proto->hasExtension()) {
      foreach ($proto->getExtensionList() as $field) {
        $this->extensions[$field->getExtendee()][] = array($namespace, $field);
      }
    }

    // Dump all extensions found in this proto file
    if (count($this->extensions)):
      $s[] = 'namespace {';
      foreach ($this->extensions as $extendee => $fields) {
        foreach ($fields as $pair) {
          list($ns, $field) = $pair;
          $s[] = $this->compileExtension($field, $ns, '  ');
        }
      }
      $s[] = '}';

      $src = implode(PHP_EOL, $s);

      // In multifile mode we output all the extensions in a file named after
      // the proto file, since it's not trivial or even possible in all cases
      // to include the extensions with the extended message file.
      $fname = pathinfo($proto->getName(), PATHINFO_FILENAME);
      $this->addComponent(NULL, $fname . '-extensions', $src);

      // Reset extensions for next proto file
      $this->extensions = array();
    endif;

    $files = array();
    if (!$this->getOption('multifile')) {
      $src = '';
      foreach ($this->components as $content) {
        $src .= $content;
      }
      $fname = pathinfo($proto->getName(), PATHINFO_FILENAME);
      $files[] = $this->buildFile($proto, $fname, $src);
    }
    else {
      foreach ($this->components as $ns => $content) {
        $fname = str_replace('\\', '/', $ns);
        $files[] = $this->buildFile($proto, $fname, $content);
      }
    }

    return $files;
  }

  protected function buildFile(proto\FileDescriptorProto $proto, $fname, $contents) {
    $suffix = $this->getOption('suffix') ? : '.php';
    $fname .= $suffix;

    $file = new \google\protobuf\compiler\CodeGeneratorResponse\File();
    $file->setName($fname);

    $s = array();
    $s[] = "<?php";
    $s[] = "// DO NOT EDIT! Generated by Protobuf-PHP protoc plugin " . Protobuf::VERSION;
    $s[] = "// Source: " . $proto->getName();
    $s[] = "//   Date: " . date('Y-m-d H:i:s');
    $s[] = "";
    $s[] = "// @@protoc_insertion_point(scope_file)";
    $s[] = "";

    $contents = implode(PHP_EOL, $s) . PHP_EOL . $contents;

    // If we don't want insertion points remove them
    if (!$this->getOption('insertions')) {
      $contents = preg_replace('#^\s*//\s+@@protoc_insertion_point.*$\n#m', '', $contents);
    }

    $file->setContent($contents);
    return $file;
  }

  protected function compileEnum(proto\EnumDescriptorProto $enum, $ns) {
    $s = array();

    $s[] = "namespace " . $this->normalizeNS($ns) . " {";
    $s[] = "";
    $s[] = "  // @@protoc_insertion_point(scope_namespace)";
    $s[] = "  // @@protoc_insertion_point(namespace_$ns)";
    $s[] = "";

    $cmt = $this->compiler->getComment($ns . '.' . $enum->getName(), '   * ');
    if ($cmt):
      $s[] = "  /**";
      $s[] = $cmt;
      $s[] = "   */";
    endif;

    $s[] = "  class " . $enum->getName() . ' extends \DrSlump\Protobuf\Enum {';
    foreach ($enum->getValueList() as $value):
      $s[] = "    const " . $value->getName() . " = " . $value->getNumber() . ";";
    endforeach;
    $s[] = "";
    $s[] = "    // @@protoc_insertion_point(scope_class)";
    $s[] = '    // @@protoc_insertion_point(class_' . $ns . '.' . $enum->getName() . ')';
    $s[] = "  }";
    $s[] = "}";
    $s[] = "";

    return implode(PHP_EOL, $s);
  }

  protected function compileMessage(proto\DescriptorProto $msg, $ns) {
    $s = array();
    $s[] = "namespace " . $this->normalizeNS($ns) . " {";
    $s[] = "";
    $s[] = "  // @@protoc_insertion_point(scope_namespace)";
    $s[] = "  // @@protoc_insertion_point(namespace_$ns)";
    $s[] = "";

    $cmt = $this->compiler->getComment($ns . '.' . $msg->getName(), '   * ');
    if ($cmt):
      $s[] = "  /**";
      $s[] = $cmt;
      $s[] = "   */";
    endif;

    // Compute a new namespace with the message name as suffix
    $ns .= '.' . $msg->getName();

    $s[] = '  class ' . $msg->getName() . ' extends \DrSlump\Protobuf\Message {';
    $s[] = '';

    foreach ($msg->getField() as $field):
      $s[] = $this->generatePublicField($field, $ns, "    ");
    endforeach;
    $s[] = '';

    $s[] = '    /** @var \Closure[] */';
    $s[] = '    protected static $__extensions = array();';
    $s[] = '';
    $s[] = '    public static function descriptor()';
    $s[] = '    {';
    $s[] = '      $descriptor = new \DrSlump\Protobuf\Descriptor(__CLASS__, \'' . $ns . '\');';
    $s[] = '';
    foreach ($msg->getField() as $field):
      $s[] = $this->compileField($field, $ns, "      ");
      $s[] = '      $descriptor->addField($f);';
      $s[] = '';
    endforeach;
    $s[] = '      foreach (self::$__extensions as $cb) {';
    $s[] = '        $descriptor->addField($cb(), true);';
    $s[] = '      }';
    $s[] = '';
    $s[] = '      // @@protoc_insertion_point(scope_descriptor)';
    $s[] = '      // @@protoc_insertion_point(descriptor_' . $ns . ')';
    $s[] = '';
    $s[] = '      return $descriptor;';
    $s[] = '    }';
    $s[] = '';

    //$s[]= "    protected static \$__exts = array(";
    //foreach ($msg->getExtensionRange() as $range):
    //$s[]= '      array(' . $range->getStart() . ', ' . ($range->getEnd()-1) . '),';
    //endforeach;
    //$s[]= "    );";
    //$s[]= "";

    foreach ($msg->getField() as $field):
      $s[] = $this->generateAccessors($field, $ns, "    ");
    endforeach;

    $s[] = "";
    $s[] = "    // @@protoc_insertion_point(scope_class)";
    $s[] = '    // @@protoc_insertion_point(class_' . $ns . ')';
    $s[] = "  }";
    $s[] = "}";
    $s[] = "";

    // Generate Enums
    if ($msg->hasEnumType()):
      foreach ($msg->getEnumType() as $enum):
        $src = $this->compileEnum($enum, $ns);
        $this->addComponent($ns, $enum->getName(), $src);
      endforeach;
    endif;

    // Generate nested messages
    if ($msg->hasNestedType()):
      foreach ($msg->getNestedType() as $msg):
        $src = $this->compileMessage($msg, $ns);
        $this->addComponent($ns, $msg->getName(), $src);
      endforeach;
    endif;

    // Collect extensions
    if ($msg->hasExtension()) {
      foreach ($msg->getExtensionList() as $field) {
        $this->extensions[$field->getExtendee()][] = array($ns, $field);
      }
    }

    return implode(PHP_EOL, $s) . PHP_EOL;
  }


  protected function compileField(proto\FieldDescriptorProto $field, $ns, $indent) {
    // Fetch constants by reflecton
    $refl = new \ReflectionClass('\DrSlump\Protobuf');
    $constants = $refl->getConstants();

    // Separate rules and types
    $rules = $types = array();
    foreach ($constants as $k => $v) {
      if (FALSE === strpos($k, '_')) {
        continue;
      }

      list($prefix, $name) = explode('_', $k, 2);
      if ('RULE' === $prefix) {
        $rules[$name] = $v;
      }
      else if ('TYPE' === $prefix) {
        $types[$name] = $v;
      }
    }

    // Get the key for the rule and type
    $rule = array_search($field->getLabel(), $rules);
    $type = array_search($field->getType(), $types);

    $s[] = "// $rule $type " . $field->getName() . " = " . $field->getNumber();
    $s[] = '$f = new \DrSlump\Protobuf\Field();';
    $s[] = '$f->number    = ' . $field->getNumber() . ';';
    $s[] = '$f->name      = "' . $field->getName() . '";';
    $s[] = '$f->type      = \DrSlump\Protobuf::TYPE_' . $type . ';';
    $s[] = '$f->rule      = \DrSlump\Protobuf::RULE_' . $rule . ';';

    if ($field->hasTypeName()):
      $ref = $field->getTypeName();
      if (substr($ref, 0, 1) !== '.') {
        throw new \RuntimeException("Only fully qualified names are supported but found '$ref' at $ns");
      }
      $s[] = '$f->reference = \'\\' . $this->normalizeNS($ref) . "';";
    endif;

    if ($field->hasDefaultValue()):
      switch ($field->getType()) {
        case Protobuf::TYPE_BOOL:
          $bool = filter_var($field->getDefaultValue(), FILTER_VALIDATE_BOOLEAN);
          $s[] = '$f->default   = ' . ($bool ? 'true' : 'false') . ';';
          break;
        case Protobuf::TYPE_STRING:
          $s[] = '$f->default   = "' . addcslashes($field->getDefaultValue(), '"\\') . '";';
          break;
        case Protobuf::TYPE_ENUM:
          $value = '\\' . $this->normalizeNS($field->getTypeName()) . '::' . $field->getDefaultValue();
          $s[] = '$f->default   = ' . $value . ';';
          break;
        default: // Numbers
          $s[] = '$f->default   = ' . $field->getDefaultValue() . ';';
      }
    endif;

    $s[] = '// @@protoc_insertion_point(scope_field)';
    $s[] = '// @@protoc_insertion_point(field_' . $ns . ':' . $field->getName() . ')';

    return $indent . implode(PHP_EOL . $indent, $s);
  }

  protected function compileExtension(proto\FieldDescriptorProto $field, $ns, $indent) {
    $extendee = $this->normalizeNS($field->getExtendee());
    $name = $this->normalizeNS($ns . '.' . $field->getName());
    $field->setName(str_replace("\\", ".", $name));

    $s[] = "\\$extendee::extension(function(){";
    $s[] = $this->compileField($field, $ns, $indent . '  ');
    $s[] = '  // @@protoc_insertion_point(scope_extension)';
    $s[] = '  // @@protoc_insertion_point(extension_' . $ns . ':' . $field->getName() . ')';
    $s[] = '  return $f;';
    $s[] = "});";

    return $indent . implode(PHP_EOL . $indent, $s);
  }

  protected function compileService(proto\ServiceDescriptorProto $service, $ns) {
    $s = array();
    $s[] = 'namespace ' . $this->normalizeNS($ns) . ' {';
    $s[] = '';
    $s[] = "  // @@protoc_insertion_point(scope_namespace)";
    $s[] = "  // @@protoc_insertion_point(namespace_$ns)";
    $s[] = '';

    $cmt = $this->compiler->getComment($ns . '.' . $service->getName(), '   * ');
    if ($cmt):
      $s[] = "  /**";
      $s[] = $cmt;
      $s[] = "   */";
    endif;

    $s[] = '  interface ' . $service->getName();
    $s[] = '  {';
    $s[] = '    // @@protoc_insertion_point(scope_interface)';
    $s[] = '    // @@protoc_insertion_point(interface_' . $ns . '.' . $service->getName() . ')';
    $s[] = '';

    foreach ($service->getMethodList() as $method):
      $s[] = '    /**';

      $cmt = $this->compiler->getComment($ns . '.' . $service->getName() . '.' . $method->getName(), '     * ');
      if ($cmt):
        $s[] = $cmt;
        $s[] = '     * ';
      endif;

      $s[] = '     * @param ' . $this->normalizeNS($method->getInputType()) . ' $input';
      $s[] = '     * @return ' . $this->normalizeNS($method->getOutputType());
      $s[] = '     */';
      $s[] = '    public function ' . $method->getName() . '(' . $this->normalizeNS($method->getInputType()) . ' $input);';
      $s[] = '';
    endforeach;
    $s[] = '  }';
    $s[] = '}';
    $s[] = '';

    return implode(PHP_EOL, $s) . PHP_EOL;
  }

  protected function generatePublicField(proto\FieldDescriptorProto $field, $ns, $indent) {
    $cmt = $this->compiler->getComment($ns . '.' . $field->getNumber(), "$indent * ");
    if ($cmt) {
      $cmt = "\n" . $cmt . "\n$indent *";
    }

    if ($field->getLabel() === Protobuf::RULE_REPEATED) {
      $s[] = "/** $cmt @var " . $this->getJavaDocType($field) . "[] " . ($cmt ? "\n$indent" : '') . " */";
      $s[] = 'public $' . $field->getName() . " = array();";
    }
    else {
      $s[] = "/** $cmt @var " . $this->getJavaDocType($field) . ($cmt ? "\n$indent" : '') . " */";
      $default = 'null';
      if ($field->hasDefaultValue()) {
        switch ($field->getType()) {
          case Protobuf::TYPE_BOOL:
            $bool = filter_var($field->getDefaultValue(), FILTER_VALIDATE_BOOLEAN);
            $default = $bool ? 'true' : 'false';
            break;
          case Protobuf::TYPE_STRING:
            $default = '"' . addcslashes($field->getDefaultValue(), '"\\') . '"';
            break;
          case Protobuf::TYPE_ENUM:
            $default = '\\' . $this->normalizeNS($field->getTypeName()) . '::' . $field->getDefaultValue();
            break;
          default: // Numbers
            $default = $field->getDefaultValue();
        }
      }
      $s[] = 'public $' . $field->getName() . ' = ' . $default . ';';
    }
    $s[] = "";

    return $indent . implode(PHP_EOL . $indent, $s);
  }

  protected function generateAccessors(proto\FieldDescriptorProto $field, $ns, $indent) {
    $tag = $field->getNumber();
    $name = $field->getName();
    $camel = $this->compiler->camelize(ucfirst($name));

    $typehint = '';
    $typedoc = $this->getJavaDocType($field);
    if (0 === strpos($typedoc, '\\')) {
      $typehint = $typedoc;
    }

    // hasXXX
    $s[] = "/**";
    $s[] = " * Check if <$name> has a value";
    $s[] = " *";
    $s[] = " * @return boolean";
    $s[] = " */";
    $s[] = "public function has$camel(){";
    $s[] = "  return \$this->_has($tag);";
    $s[] = "}";
    $s[] = "";

    // clearXXX
    $s[] = "/**";
    $s[] = " * Clear <$name> value";
    $s[] = " *";
    $s[] = " * @return \\" . $this->normalizeNS($ns);
    $s[] = " */";
    $s[] = "public function clear$camel(){";
    $s[] = "  return \$this->_clear($tag);";
    $s[] = "}";
    $s[] = "";

    if ($field->getLabel() === Protobuf::RULE_REPEATED):

      // getXXX
      $s[] = "/**";
      $s[] = " * Get <$name> value";
      $s[] = " *";
      $s[] = " * @param int \$idx";
      $s[] = " * @return $typedoc";
      $s[] = " */";
      $s[] = "public function get$camel(\$idx = NULL){";
      $s[] = "  return \$this->_get($tag, \$idx);";
      $s[] = "}";
      $s[] = "";

      // setXXX
      $s[] = "/**";
      $s[] = " * Set <$name> value";
      $s[] = " *";
      $s[] = " * @param $typedoc \$value";
      $s[] = " * @return \\" . $this->normalizeNS($ns);
      $s[] = " */";
      $s[] = "public function set$camel($typehint \$value, \$idx = NULL){";
      $s[] = "  return \$this->_set($tag, \$value, \$idx);";
      $s[] = "}";
      $s[] = "";

      $s[] = "/**";
      $s[] = " * Get all elements of <$name>";
      $s[] = " *";
      $s[] = " * @return {$typedoc}[]";
      $s[] = " */";
      $s[] = "public function get{$camel}List(){";
      $s[] = " return \$this->_get($tag);";
      $s[] = "}";
      $s[] = "";

      $s[] = "/**";
      $s[] = " * Add a new element to <$name>";
      $s[] = " *";
      $s[] = " * @param $typedoc \$value";
      $s[] = " * @return \\" . $this->normalizeNS($ns);
      $s[] = " */";
      $s[] = "public function add$camel($typehint \$value){";
      $s[] = " return \$this->_add($tag, \$value);";
      $s[] = "}";
      $s[] = "";

    else:

      // getXXX
      $s[] = "/**";
      $s[] = " * Get <$name> value";
      $s[] = " *";
      $s[] = " * @return $typedoc";
      $s[] = " */";
      $s[] = "public function get$camel(){";
      $s[] = "  return \$this->_get($tag);";
      $s[] = "}";
      $s[] = "";

      // setXXX
      $s[] = "/**";
      $s[] = " * Set <$name> value";
      $s[] = " *";
      $s[] = " * @param $typedoc \$value";
      $s[] = " * @return \\" . $this->normalizeNS($ns);
      $s[] = " */";
      $s[] = "public function set$camel($typehint \$value){";
      $s[] = "  return \$this->_set($tag, \$value);";
      $s[] = "}";
      $s[] = "";

    endif;

    return $indent . implode(PHP_EOL . $indent, $s);
  }

  protected function getJavaDocType(proto\FieldDescriptorProto $field) {
    switch ($field->getType()) {
      case Protobuf::TYPE_DOUBLE:
      case Protobuf::TYPE_FLOAT:
        return 'float';
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
        return 'int';
      case Protobuf::TYPE_BOOL:
        return 'boolean';
      case Protobuf::TYPE_STRING:
        return 'string';
      case Protobuf::TYPE_MESSAGE:
        return '\\' . $this->normalizeNS($field->getTypeName());
      case Protobuf::TYPE_BYTES:
        return 'string';
      case Protobuf::TYPE_ENUM:
        return 'int - \\' . $this->normalizeNS($field->getTypeName());

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
      $namespace = str_replace('.', '\\', $package);
    }
    else {
      // Complete the namespace with the remaining package
      $namespace = $this->compiler->getPackage($found);
      $namespace .= substr($package, strlen($found));
      $namespace = str_replace('.', '\\', $namespace);
      // Set the newly found namespace in the registry
      $this->compiler->setPackage($package, $namespace);
    }

    return $namespace;
  }
}
