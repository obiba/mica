<?php
$path_module_protobuf = drupal_get_path('module', 'obiba_protobuf');
$path_module_protos = drupal_get_path('module', 'mica_export_client_model');

include_once($path_module_protobuf . '/protobuf/Protobuf.php');
use \DrSlump\Protobuf;

Protobuf::autoload();

include_once($path_module_protos . '/protos/Mica.php');

class QuerySendDto {
  protected $micaUrl;

  public function __construct($mica_url = NULL) {
    $this->micaUrl = (isset($mica_url) ? $mica_url : variable_get_value('mica_url')) . '/ws';
  }

  public function get_from_mica_server($resource) {
    $url = $this->micaUrl . $resource;
    // authenticate by credentials
    $credentials = variable_get_value('mica_admin_name') . ':' . variable_get_value('mica_admin_password');
    $headers = array('Accept' => array('application/json'));
    $headers['Authorization'] = array('Basic ' . base64_encode($credentials));

    $request = new HttpClientRequest($url, array(
      'method' => HttpClientRequest::METHOD_GET,
      'headers' => $headers
    ));

    $client = new HttpClient($formatter = FALSE);
    if (!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSLVERSION => 3,
      CURLOPT_SSL_VERIFYHOST => FALSE,
      CURLOPT_SSL_VERIFYPEER => FALSE
    );
    try {
      return $client->execute($request);
    } catch (HttpClientException $e) {
      drupal_set_message(t('Can\'t procceed your request server return : ') . $e->getMessage(), 'error');
      drupal_set_message(t('Error Detail : ') . $client->lastResponse->body, 'error');
      return FALSE;
    }
  }

  public function save_operation($data, $resource, $method_request, $node_type) {
    $url = $this->micaUrl . '/' . $resource;
    // authenticate by credentials
    $credentials = variable_get_value('mica_admin_name') . ':' . variable_get_value('mica_admin_password');
    $headers = array('Content-Type' => array('application/json'));
    $headers['Authorization'] = array('Basic ' . base64_encode($credentials));
//    dpm($url);
//    dpm($data);
    $request = new HttpClientRequest(trim($url), array(
      'method' => constant("HttpClientRequest::$method_request"),
      'headers' => $headers,
      'data' => $data,
    ));
    $client = new HttpClient($formatter = FALSE);
    if (!isset($client->options['curlopts'])) {
      $client->options['curlopts'] = array();
    }

    $client->options['curlopts'] += array(
      CURLOPT_SSLVERSION => 3,
      CURLOPT_SSL_VERIFYHOST => FALSE,
      CURLOPT_SSL_VERIFYPEER => FALSE
    );
    try {
      $client->execute($request);
      if (preg_match('/(?<=\/' . $node_type . '\/).*/', $client->lastResponse->headers, $group)) {
        $match = $group[0];
      }
      drupal_set_message(t($node_type . ' success saved with server response  : ') . $client->lastResponse->responseMessage, 'status');
      return trim($match);
    } catch (HttpClientException $e) {
      drupal_set_message('save ' . $resource . 'Method ' . $method_request, 'error');
      drupal_set_message(t('Can\'t procceed your request server return : ') . $e->getMessage(), 'error');
      drupal_set_message(t('Error Detail : ') . $client->lastResponse->body, 'error');
      return FALSE;
    }
  }

  public function export_file($attachement) {
//  //@TODO deal with attachement files

    // authenticate by credentials
    $credentials = variable_get_value('mica_admin_name') . ':' . variable_get_value('mica_admin_password');
    $headers['Authorization'] = array();

    $file_tmp_uri = $this->_copy_attachment_file($attachement);
    $file_info = new finfo(FILEINFO_MIME);
    $mime_file = $file_info->file($file_tmp_uri);
    $mica_url = variable_get_value('mica_url');
    $url = $mica_url . '/ws/files/temp';
    $cfile = new CurlFile($file_tmp_uri, $mime_file, $attachement['filename']);
    $data_file = array('file' => $cfile);
    $resource = curl_init();
    curl_setopt($resource, CURLOPT_URL, $url);
    curl_setopt($resource, CURLOPT_HEADER, TRUE);
    curl_setopt($resource, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($resource, CURLINFO_HEADER_OUT, TRUE);
    curl_setopt($resource, CURLOPT_POST, 1);
    curl_setopt($resource, CURLOPT_SSLVERSION, 3);
    curl_setopt($resource, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_setopt($resource, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($resource, CURLOPT_POSTFIELDS, $data_file);
    curl_setopt($resource, CURLOPT_HTTPHEADER, array(
      'Authorization: ' . 'Basic ' . base64_encode($credentials)
    ));
    $result = curl_exec($resource);

//  $http_code = curl_getinfo($resource, CURLINFO_HTTP_CODE);
//   $http_header_out = curl_getinfo($resource);
//   dpm($http_code);
//   dpm($result);
    if (preg_match('/(?<=files\/temp\/).*/', $result, $group)) {
      $match = $group[0];
    }
    curl_close($resource);

    //dpm($match);
    return trim($match);
  }

  /**
   * Copy attachment files of each node
   */
  private function _copy_attachment_file($documents) {
    $destination = NULL;
    if (empty($documents)) {
      return;
    }

    $path = "/tmp/attachment";
    if (!is_dir($path)) {
      drupal_mkdir($path);
    }
    $destination = $path . "/" . $documents['filename'];
    if (!empty($documents)) {
      file_unmanaged_copy($documents['uri'], $destination, FILE_EXISTS_REPLACE);
    }

    return $destination;
  }


  //Deal with multi lang content
  function _mica_studies_export_json_add_translated_Field($dto_obj, $dto_method, $wrapper, $field, $array_field = NULL, $other_getter = NULL, $index_field = NULL) {
    $default_lang = language_default();
    if (!empty($field)) {
      if (module_exists('mica_i18n')) {
        foreach (language_list() as $lang => $std_lang) {
          $field_value = $wrapper->language($lang)->{$field}->value();

          if (empty($array_field) && empty($other_getter) && empty($index_field)) {
            $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value, $lang));
          }
          if (!empty($other_getter)) {
            $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($wrapper->language($lang)->{$field}->label(), $lang));
          }
          if (!empty($array_field)) { //if($dto_method =='addDescription'){dpm($wrapper);}
            $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value[$array_field], $lang));
          }
          if (!empty($index_field)) {
            $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value[$index_field], $lang));
          }
        }
      }
      else {
        $field_value = $wrapper->{$field}->value();
        if (empty($array_field) && empty($other_getter)) {
          $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value, $default_lang->language));
        }
        if (!empty($other_getter)) {
          $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($wrapper->{$field}->label(), $default_lang->language));
        }
        if (!empty($array_field)) {
          $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value[$array_field], $default_lang->language));
        }
        if (!empty($index_field)) {
          $dto_obj->{$dto_method}($this->_set_LocalizedStringDto($field_value[$index_field], $default_lang->language));
        }
      }
    }
  }

  function _set_LocalizedStringDto($value, $lang) {
    $locate = new \obiba\mica\LocalizedStringDto();
    $locate->setLang($lang);
    $locate->setValue($value);
    return $locate;
  }

  function _set_LocalizedStringDtos($wrapper, $field, $index_field = NULL) {
    $locals = new \obiba\mica\LocalizedStringDtos();
    foreach (language_list() as $lang => $std_lang) {
      $field_value = $wrapper->language($lang)->{$field}->value();
      $locals->addLocalizedStrings($this->_set_LocalizedStringDto($field_value[$index_field], $lang));
    }
    return $locals;
  }

  function _set_gender_to_export_dto($gender) {

    switch ($gender) {
      case 'men' :
        return 0;
        break;
      case 'women' :
        return 1;
        break;
      default :
        NULL;
    }

  }

  function _mica_studies_export_json_attachement_construct($attachment, $type = 'document') {
    $attachement_dto = new \obiba\mica\AttachmentDto;
    $attachement_dto->setId($attachment['uuid']);
    $attachement_dto->setJustUploaded(TRUE);
    $attachement_dto->setType($type);
    $attachement_dto->addDescription($this->_set_LocalizedStringDto($attachment['description'], 'en'));
    $attachement_dto->setFileName($attachment['filename']);
    $attachement_dto->setLang('en');
    return $attachement_dto;
  }

  function _convert_Iso2_to_3($iso_code_2) {
    $convert2to3["AF"] = "AFG";
    $convert2to3["AX"] = "ALA";
    $convert2to3["AL"] = "ALB";
    $convert2to3["DZ"] = "DZA";
    $convert2to3["AS"] = "ASM";
    $convert2to3["AD"] = "AND";
    $convert2to3["AO"] = "AGO";
    $convert2to3["AI"] = "AIA";
    $convert2to3["AQ"] = "ATA";
    $convert2to3["AG"] = "ATG";
    $convert2to3["AR"] = "ARG";
    $convert2to3["AM"] = "ARM";
    $convert2to3["AW"] = "ABW";
    $convert2to3["AU"] = "AUS";
    $convert2to3["AT"] = "AUT";
    $convert2to3["AZ"] = "AZE";
    $convert2to3["BS"] = "BHS";
    $convert2to3["BH"] = "BHR";
    $convert2to3["BD"] = "BGD";
    $convert2to3["BB"] = "BRB";
    $convert2to3["BY"] = "BLR";
    $convert2to3["BE"] = "BEL";
    $convert2to3["BZ"] = "BLZ";
    $convert2to3["BJ"] = "BEN";
    $convert2to3["BM"] = "BMU";
    $convert2to3["BT"] = "BTN";
    $convert2to3["BO"] = "BOL";
    $convert2to3["BA"] = "BIH";
    $convert2to3["BW"] = "BWA";
    $convert2to3["BV"] = "BVT";
    $convert2to3["BR"] = "BRA";
    $convert2to3["IO"] = "IOT";
    $convert2to3["BN"] = "BRN";
    $convert2to3["BG"] = "BGR";
    $convert2to3["BF"] = "BFA";
    $convert2to3["BI"] = "BDI";
    $convert2to3["KH"] = "KHM";
    $convert2to3["CM"] = "CMR";
    $convert2to3["CA"] = "CAN";
    $convert2to3["CV"] = "CPV";
    $convert2to3["KY"] = "CYM";
    $convert2to3["CF"] = "CAF";
    $convert2to3["TD"] = "TCD";
    $convert2to3["CL"] = "CHL";
    $convert2to3["CN"] = "CHN";
    $convert2to3["CX"] = "CXR";
    $convert2to3["CC"] = "CCK";
    $convert2to3["CO"] = "COL";
    $convert2to3["KM"] = "COM";
    $convert2to3["CG"] = "COG";
    $convert2to3["CD"] = "COD";
    $convert2to3["CK"] = "COK";
    $convert2to3["CR"] = "CRI";
    $convert2to3["CI"] = "CIV";
    $convert2to3["HR"] = "HRV";
    $convert2to3["CU"] = "CUB";
    $convert2to3["CY"] = "CYP";
    $convert2to3["CZ"] = "CZE";
    $convert2to3["DK"] = "DNK";
    $convert2to3["DJ"] = "DJI";
    $convert2to3["DM"] = "DMA";
    $convert2to3["DO"] = "DOM";
    $convert2to3["EC"] = "ECU";
    $convert2to3["EG"] = "EGY";
    $convert2to3["SV"] = "SLV";
    $convert2to3["GQ"] = "GNQ";
    $convert2to3["ER"] = "ERI";
    $convert2to3["EE"] = "EST";
    $convert2to3["ET"] = "ETH";
    $convert2to3["FK"] = "FLK";
    $convert2to3["FO"] = "FRO";
    $convert2to3["FJ"] = "FJI";
    $convert2to3["FI"] = "FIN";
    $convert2to3["FR"] = "FRA";
    $convert2to3["GF"] = "GUF";
    $convert2to3["PF"] = "PYF";
    $convert2to3["TF"] = "ATF";
    $convert2to3["GA"] = "GAB";
    $convert2to3["GM"] = "GMB";
    $convert2to3["GE"] = "GEO";
    $convert2to3["DE"] = "DEU";
    $convert2to3["GH"] = "GHA";
    $convert2to3["GI"] = "GIB";
    $convert2to3["GR"] = "GRC";
    $convert2to3["GL"] = "GRL";
    $convert2to3["GD"] = "GRD";
    $convert2to3["GP"] = "GLP";
    $convert2to3["GU"] = "GUM";
    $convert2to3["GT"] = "GTM";
    $convert2to3["GG"] = "GGY";
    $convert2to3["GN"] = "GIN";
    $convert2to3["GW"] = "GNB";
    $convert2to3["GY"] = "GUY";
    $convert2to3["HT"] = "HTI";
    $convert2to3["HM"] = "HMD";
    $convert2to3["VA"] = "VAT";
    $convert2to3["HN"] = "HND";
    $convert2to3["HK"] = "HKG";
    $convert2to3["HU"] = "HUN";
    $convert2to3["IS"] = "ISL";
    $convert2to3["IN"] = "IND";
    $convert2to3["ID"] = "IDN";
    $convert2to3["IR"] = "IRN";
    $convert2to3["IQ"] = "IRQ";
    $convert2to3["IE"] = "IRL";
    $convert2to3["IM"] = "IMM";
    $convert2to3["IL"] = "ISR";
    $convert2to3["IT"] = "ITA";
    $convert2to3["JM"] = "JAM";
    $convert2to3["JP"] = "JPN";
    $convert2to3["JE"] = "JEY";
    $convert2to3["JO"] = "JOR";
    $convert2to3["KZ"] = "KAZ";
    $convert2to3["KE"] = "KEN";
    $convert2to3["KI"] = "KIR";
    $convert2to3["KP"] = "PRK";
    $convert2to3["KR"] = "KOR";
    $convert2to3["KW"] = "KWT";
    $convert2to3["KG"] = "KGZ";
    $convert2to3["LA"] = "LAO";
    $convert2to3["LV"] = "LVA";
    $convert2to3["LB"] = "LBN";
    $convert2to3["LS"] = "LSO";
    $convert2to3["LR"] = "LBR";
    $convert2to3["LY"] = "LBY";
    $convert2to3["LI"] = "LIE";
    $convert2to3["LT"] = "LTU";
    $convert2to3["LU"] = "LUX";
    $convert2to3["MO"] = "MAC";
    $convert2to3["MK"] = "MKD";
    $convert2to3["MG"] = "MDG";
    $convert2to3["MW"] = "MWI";
    $convert2to3["MY"] = "MYS";
    $convert2to3["MV"] = "MDV";
    $convert2to3["ML"] = "MLI";
    $convert2to3["MT"] = "MLT";
    $convert2to3["MH"] = "MHL";
    $convert2to3["MQ"] = "MTQ";
    $convert2to3["MR"] = "MRT";
    $convert2to3["MU"] = "MUS";
    $convert2to3["YT"] = "MYT";
    $convert2to3["MX"] = "MEX";
    $convert2to3["FM"] = "FSM";
    $convert2to3["MD"] = "MDA";
    $convert2to3["MC"] = "MCO";
    $convert2to3["MN"] = "MNG";
    $convert2to3["ME"] = "MNE";
    $convert2to3["MS"] = "MSR";
    $convert2to3["MA"] = "MAR";
    $convert2to3["MZ"] = "MOZ";
    $convert2to3["MM"] = "MMR";
    $convert2to3["NA"] = "NAM";
    $convert2to3["NR"] = "NRU";
    $convert2to3["NP"] = "NPL";
    $convert2to3["NL"] = "NLD";
    $convert2to3["AN"] = "ANT";
    $convert2to3["NC"] = "NCL";
    $convert2to3["NZ"] = "NZL";
    $convert2to3["NI"] = "NIC";
    $convert2to3["NE"] = "NER";
    $convert2to3["NG"] = "NGA";
    $convert2to3["NU"] = "NIU";
    $convert2to3["NF"] = "NFK";
    $convert2to3["MP"] = "MNP";
    $convert2to3["NO"] = "NOR";
    $convert2to3["OM"] = "OMN";
    $convert2to3["PK"] = "PAK";
    $convert2to3["PW"] = "PLW";
    $convert2to3["PS"] = "PSE";
    $convert2to3["PA"] = "PAN";
    $convert2to3["PG"] = "PNG";
    $convert2to3["PY"] = "PRY";
    $convert2to3["PE"] = "PER";
    $convert2to3["PH"] = "PHL";
    $convert2to3["PN"] = "PCN";
    $convert2to3["PL"] = "POL";
    $convert2to3["PT"] = "PRT";
    $convert2to3["PR"] = "PRI";
    $convert2to3["QA"] = "QAT";
    $convert2to3["RE"] = "REU";
    $convert2to3["RO"] = "ROU";
    $convert2to3["RU"] = "RUS";
    $convert2to3["RW"] = "RWA";
    $convert2to3["BL"] = "BLM";
    $convert2to3["SH"] = "SHN";
    $convert2to3["KN"] = "KNA";
    $convert2to3["LC"] = "LCA";
    $convert2to3["MT"] = "MAF";
    $convert2to3["PM"] = "SPM";
    $convert2to3["VC"] = "VCT";
    $convert2to3["WS"] = "WSM";
    $convert2to3["SM"] = "SMR";
    $convert2to3["ST"] = "STP";
    $convert2to3["SA"] = "SAU";
    $convert2to3["SN"] = "SEN";
    $convert2to3["RS"] = "SRB";
    $convert2to3["SC"] = "SYC";
    $convert2to3["SL"] = "SLE";
    $convert2to3["SG"] = "SGP";
    $convert2to3["SK"] = "SVK";
    $convert2to3["SI"] = "SVN";
    $convert2to3["SB"] = "SLB";
    $convert2to3["SO"] = "SOM";
    $convert2to3["ZA"] = "ZAF";
    $convert2to3["GS"] = "SGS";
    $convert2to3["ES"] = "ESP";
    $convert2to3["LK"] = "LKA";
    $convert2to3["SD"] = "SDN";
    $convert2to3["SR"] = "SUR";
    $convert2to3["SJ"] = "SJM";
    $convert2to3["SZ"] = "SWZ";
    $convert2to3["SE"] = "SWE";
    $convert2to3["CH"] = "CHE";
    $convert2to3["SY"] = "SYR";
    $convert2to3["TW"] = "TWN";
    $convert2to3["TJ"] = "TJK";
    $convert2to3["TZ"] = "TZA";
    $convert2to3["TH"] = "THA";
    $convert2to3["TL"] = "TLS";
    $convert2to3["TG"] = "TGO";
    $convert2to3["TK"] = "TKL";
    $convert2to3["TO"] = "TON";
    $convert2to3["TT"] = "TTO";
    $convert2to3["TN"] = "TUN";
    $convert2to3["TR"] = "TUR";
    $convert2to3["TM"] = "TKM";
    $convert2to3["TC"] = "TCA";
    $convert2to3["TV"] = "TUV";
    $convert2to3["UG"] = "UGA";
    $convert2to3["UA"] = "UKR";
    $convert2to3["AE"] = "ARE";
    $convert2to3["GB"] = "GBR";
    $convert2to3["US"] = "USA";
    $convert2to3["UM"] = "UMI";
    $convert2to3["UY"] = "URY";
    $convert2to3["UZ"] = "UZB";
    $convert2to3["VU"] = "VUT";
    $convert2to3["VA"] = "VAT";
    $convert2to3["VE"] = "VEN";
    $convert2to3["VN"] = "VNM";
    $convert2to3["VG"] = "VGB";
    $convert2to3["VI"] = "VIR";
    $convert2to3["WF"] = "WLF";
    $convert2to3["EH"] = "ESH";
    $convert2to3["YE"] = "YEM";
    $convert2to3["YU"] = "YUG";
    $convert2to3["ZM"] = "ZMB";
    $convert2to3["ZW"] = "ZWE";
    if (isset($convert2to3[$iso_code_2])) {
      return $convert2to3[$iso_code_2];
    }
    else {
      return NULL;
    }
  }

}
