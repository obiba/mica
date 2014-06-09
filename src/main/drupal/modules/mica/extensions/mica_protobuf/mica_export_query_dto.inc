<?php

include_once('protobuf/Protobuf.php');
use \DrSlump\Protobuf;

Protobuf::autoload();

const HEADER_BINARY = 'application/x-protobuf';
const HEADER_JSON = 'application/json';

include_once('protobuf/protos/Mica.php');
