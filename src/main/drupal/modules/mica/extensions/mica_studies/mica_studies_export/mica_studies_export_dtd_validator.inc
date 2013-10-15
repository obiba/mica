<?php
/**
 * @file
 * mica_studies_export_dtd_validator.inc
 */

function _mica_studies_export_dtd_validator() {
  $dtd_validator = '<!ELEMENT study (title,acronym,investigators,contacts,objectives,web-site,study-designs,access,maker-paper,pubmed-id,supplementary-information,populations,files)>
        <!ATTLIST study
                uuid CDATA #REQUIRED
                mica_origin_url CDATA #IMPLIED>
        <!ELEMENT title (#PCDATA)>
        <!ELEMENT acronym (#PCDATA)>
        <!ELEMENT investigators (investigator*)>
        <!ELEMENT investigator (#PCDATA)>
        <!ATTLIST investigator
                ref-uuid CDATA #REQUIRED>
        <!ELEMENT contacts (contact*)>
        <!ELEMENT contact (#PCDATA)>
        <!ATTLIST contact
                ref-uuid CDATA #REQUIRED>
        <!ELEMENT objectives (body,summary,format)>
        <!ELEMENT body (#PCDATA)>
        <!ELEMENT summary (#PCDATA)>
        <!ELEMENT format (#PCDATA)>
        <!ELEMENT web-site (#PCDATA)>
        <!ELEMENT study-designs (designs,general-information-follow-up,recruitment-target,supplementary-information,number-participant,timeline)>
        <!ELEMENT designs (design*|other_design)*>
        <!ELEMENT design (#PCDATA)>
        <!ATTLIST design
                code (case_control|case_only|clinical_trial|cohort_study|cross_sectional|other) #IMPLIED>
        <!ELEMENT other_design (#PCDATA)>
        <!ATTLIST other_design
                format (full_html|bootstrap|plain_text|php_code|filtered_html) #IMPLIED>
        <!ELEMENT general-information-follow-up (#PCDATA)>
        <!ATTLIST general-information-follow-up
                format (full_html|bootstrap|plain_text|php_code|filtered_html) #IMPLIED>
        <!ELEMENT recruitment-target (target*|other_target)*>
        <!ELEMENT target (#PCDATA)>
        <!ATTLIST target
                code (individuals|families|other) #REQUIRED>
        <!ELEMENT other_target (#PCDATA)>
        <!ATTLIST other_target
                format (full_html|bootstrap|plain_text|php_code|filtered_html) #IMPLIED>
        <!ELEMENT supplementary-information (#PCDATA)>
        <!ATTLIST supplementary-information
                format (full_html|bootstrap|plain_text|php_code|filtered_html) #IMPLIED>
        <!ELEMENT number-participant (target-number-of-participants,target-number-of-participants-with-biosamples,supplementary-information)>
        <!ELEMENT target-number-of-participants (number,no-limits)>
        <!ELEMENT number (#PCDATA)>
        <!ELEMENT no-limits (#PCDATA)>
        <!ELEMENT target-number-of-participants-with-biosamples (number,no-limits)>
        <!ELEMENT timeline (start-year,end-year)>
        <!ELEMENT start-year (#PCDATA)>
        <!ELEMENT end-year (#PCDATA)>
        <!ELEMENT access (data,biosamples,other_access,other-info)>
        <!ELEMENT data (#PCDATA)>
        <!ELEMENT biosamples (#PCDATA)>
        <!ELEMENT other_access (#PCDATA)>
        <!ELEMENT other-info (#PCDATA)>
        <!ATTLIST other-info
                format (full_html|bootstrap|plain_text|php_code|filtered_html) #IMPLIED>
        <!ELEMENT maker-paper (#PCDATA)>
        <!ELEMENT pubmed-id (#PCDATA)>
        <!ELEMENT populations (population*)>
        <!ELEMENT population (#PCDATA)>
        <!ATTLIST population
                ref-uuid CDATA #REQUIRED>
        <!ELEMENT files (documents,logo)>
        <!ELEMENT documents (document*)>
        <!ELEMENT document (filename,description,filemime,filesize)>
        <!ATTLIST document
                ref-uuid CDATA #REQUIRED>
        <!ELEMENT logo (filename,description,filemime,filesize)>
        <!ATTLIST logo
                ref-uuid CDATA #REQUIRED>
        <!ELEMENT filename (#PCDATA)>
        <!ELEMENT description (#PCDATA)>
        <!ELEMENT filemime (#PCDATA)>
        <!ELEMENT filesize (#PCDATA)>';
  return $dtd_validator;

}