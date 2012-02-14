<?php
/**
 * @file
 * mica_data_access.features.content.inc
 */

/**
 * Implements hook_content_defaults().
 */
function mica_data_access_content_defaults() {
  $content = array();

  $content['data_access'] = (object) array(
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/data_access',
      'router_path' => 'node/%',
      'link_title' => 'Data Access',
      'options' => array(
        'attributes' => array(
          'title' => '',
        ),
      ),
      'module' => 'menu',
      'hidden' => '0',
      'external' => '0',
      'has_children' => '1',
      'expanded' => '1',
      'weight' => '35',
      'identifier' => 'main-menu:node-name/data_access',
    ),
    'exported_path' => 'content/data-access',
    'title' => 'Data Access',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794227',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'data_access',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>This section aims to inform researchers about the consortium data access policy and its committee. It provides a simple data request &nbsp;web form as an example of what can be achieved for managing researcher\\&#39;s requests. As usual, the content and the form of this section can be easily customized.</p>
                    ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>This section aims to inform researchers about the consortium data access policy and its committee. It provides a simple data request  web form as an example of what can be achieved for managing researcher\\\'s requests. As usual, the content and the form of this section can be easily customized.</p>
  ',
          'safe_summary' => '',
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => '<p>Cette section permet d&#39;informer les chercheurs &agrave; propos de la politique d&#39;acc&egrave;s aux donn&eacute;es du consortium et son comit&eacute;. It provides a simple data request &nbsp;web form as an example of what can be achieved for managing researcher\\&#39;s requests. As usual, the content and the form of this section can be easily customized.</p>
              ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>Cette section permet d\'informer les chercheurs à propos de la politique d\'accès aux données du consortium et son comité. It provides a simple data request  web form as an example of what can be achieved for managing researcher\\\'s requests. As usual, the content and the form of this section can be easily customized.</p>
  ',
          'safe_summary' => '',
        ),
      ),
    ),
  );

  $content['data_access_policy'] = (object) array(
    'link' => array(
      'menu_name' => 'main-menu',
      'link_path' => 'node-name/data_access_policy',
      'router_path' => 'node/%',
      'link_title' => 'Data Access Policy',
      'options' => array(
        'attributes' => array(),
      ),
      'module' => 'menu',
      'hidden' => '0',
      'external' => '0',
      'has_children' => '1',
      'expanded' => '0',
      'weight' => '-50',
      'parent_path' => 'node-name/data_access',
      'identifier' => 'main-menu:node-name/data_access_policy',
    ),
    'exported_path' => 'content/consortium-policies-and-guidelines',
    'title' => 'Consortium Policies and Guidelines',
    'status' => '1',
    'promote' => '0',
    'sticky' => '0',
    'type' => 'page',
    'language' => 'en',
    'created' => '1328794227',
    'comment' => '1',
    'translate' => '0',
    'machine_name' => 'data_access_policy',
    'body' => array(
      'en' => array(
        0 => array(
          'value' => '<p>In planning the Consortium, the Scientific Planning Committee recognized the importance of generating a document that would be communicated widely, and contain sufficient information to allow funding agencies and scientists in many countries to make decisions on future participation. Incomplete scientific knowledge (such as tumor heterogeneity for many cancers), rapidly evolving technologies e.g., next generation sequencing technologies, diversity of funding mechanisms, and differences across nations in regards to informed consent and/or sharing of samples across international boundaries are examples of issues that were considered by the committee and its working groups. The approach adopted by the planning teams has been to define a limited number of principles that are central to participation in the project, and provide recommendations to readers based on what is considered &ldquo;best practices&rdquo; at the time of writing this document. The authors attempted to discriminate essential from recommended principles using the terms &ldquo;policy&rdquo; and &ldquo;guideline&rdquo;.</p>
                    <h2>
                    	What is a consortium policy?</h2>
                    <p>A consortium policy is a principle which consortium members agree to follow, during the course of the project. Although policies will likely be long-lasting, the Consortium will periodically review its policies.</p>
                    <h2>
                    	What is a consortium guideline?</h2>
                    <p>Consortium guidelines refer to recommendations made by Consortium working groups that offer advice as to what is believed to constitute &ldquo;best practices&rdquo; at a given time. Given the rapid evolution in technologies or new knowledge gleaned from the data generated by Consortium or other groups, it is expected that guidelines will evolve. It is also expected that approaches will need to vary based on tumor types, local laws, or other factors. In such cases, it is expected that Consortium members will be able to compare and explain differences in approaches, relative to Consortium guidelines. The Consortium has chosen to make most of its recommendations as guidelines rather than policies to allow flexibility in approaches and promote innovation. In this document, guidelines are often written in blue-shaded boxes. In this first document prepared by the Consortium, the authors strived to differentiate recommendations that are policy from those that are guidelines (even if some issues are clearly a mix of both). It is up to individual projects that join the Consortium to declare a clear plan, e.g., samples, criteria for being a sample, exons used, quality control, etc. Over time, the Consortium will generate best practices documents that will describe the current state-of-the-art, and propose modifications of the guidelines.</p>
                    ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>In planning the Consortium, the Scientific Planning Committee recognized the importance of generating a document that would be communicated widely, and contain sufficient information to allow funding agencies and scientists in many countries to make decisions on future participation. Incomplete scientific knowledge (such as tumor heterogeneity for many cancers), rapidly evolving technologies e.g., next generation sequencing technologies, diversity of funding mechanisms, and differences across nations in regards to informed consent and/or sharing of samples across international boundaries are examples of issues that were considered by the committee and its working groups. The approach adopted by the planning teams has been to define a limited number of principles that are central to participation in the project, and provide recommendations to readers based on what is considered “best practices” at the time of writing this document. The authors attempted to discriminate essential from recommended principles using the terms “policy” and “guideline”.</p>
  <h2>
                    	What is a consortium policy?</h2>
  <p>A consortium policy is a principle which consortium members agree to follow, during the course of the project. Although policies will likely be long-lasting, the Consortium will periodically review its policies.</p>
  <h2>
                    	What is a consortium guideline?</h2>
  <p>Consortium guidelines refer to recommendations made by Consortium working groups that offer advice as to what is believed to constitute “best practices” at a given time. Given the rapid evolution in technologies or new knowledge gleaned from the data generated by Consortium or other groups, it is expected that guidelines will evolve. It is also expected that approaches will need to vary based on tumor types, local laws, or other factors. In such cases, it is expected that Consortium members will be able to compare and explain differences in approaches, relative to Consortium guidelines. The Consortium has chosen to make most of its recommendations as guidelines rather than policies to allow flexibility in approaches and promote innovation. In this document, guidelines are often written in blue-shaded boxes. In this first document prepared by the Consortium, the authors strived to differentiate recommendations that are policy from those that are guidelines (even if some issues are clearly a mix of both). It is up to individual projects that join the Consortium to declare a clear plan, e.g., samples, criteria for being a sample, exons used, quality control, etc. Over time, the Consortium will generate best practices documents that will describe the current state-of-the-art, and propose modifications of the guidelines.</p>
  ',
          'safe_summary' => '',
        ),
      ),
      'fr' => array(
        0 => array(
          'value' => '<p>In planning the Consortium, the Scientific Planning Committee recognized the importance of generating a document that would be communicated widely, and contain sufficient information to allow funding agencies and scientists in many countries to make decisions on future participation. Incomplete scientific knowledge (such as tumor heterogeneity for many cancers), rapidly evolving technologies e.g., next generation sequencing technologies, diversity of funding mechanisms, and differences across nations in regards to informed consent and/or sharing of samples across international boundaries are examples of issues that were considered by the committee and its working groups. The approach adopted by the planning teams has been to define a limited number of principles that are central to participation in the project, and provide recommendations to readers based on what is considered &ldquo;best practices&rdquo; at the time of writing this document. The authors attempted to discriminate essential from recommended principles using the terms &ldquo;policy&rdquo; and &ldquo;guideline&rdquo;.</p>
              <h2>
              	Qu&#39;est-ce qu&#39;une politique de consortium?</h2>
              <p>A consortium policy is a principle which consortium members agree to follow, during the course of the project. Although policies will likely be long-lasting, the Consortium will periodically review its policies.</p>
              <h2>
              	Qu&#39;est-ce qu&#39;une ligne directrice de consortium?</h2>
              <p>Consortium guidelines refer to recommendations made by Consortium working groups that offer advice as to what is believed to constitute &ldquo;best practices&rdquo; at a given time. Given the rapid evolution in technologies or new knowledge gleaned from the data generated by Consortium or other groups, it is expected that guidelines will evolve. It is also expected that approaches will need to vary based on tumor types, local laws, or other factors. In such cases, it is expected that Consortium members will be able to compare and explain differences in approaches, relative to Consortium guidelines. The Consortium has chosen to make most of its recommendations as guidelines rather than policies to allow flexibility in approaches and promote innovation. In this document, guidelines are often written in blue-shaded boxes. In this first document prepared by the Consortium, the authors strived to differentiate recommendations that are policy from those that are guidelines (even if some issues are clearly a mix of both). It is up to individual projects that join the Consortium to declare a clear plan, e.g., samples, criteria for being a sample, exons used, quality control, etc. Over time, the Consortium will generate best practices documents that will describe the current state-of-the-art, and propose modifications of the guidelines.</p>
              ',
          'summary' => '',
          'format' => 'full_html',
          'safe_value' => '<p>In planning the Consortium, the Scientific Planning Committee recognized the importance of generating a document that would be communicated widely, and contain sufficient information to allow funding agencies and scientists in many countries to make decisions on future participation. Incomplete scientific knowledge (such as tumor heterogeneity for many cancers), rapidly evolving technologies e.g., next generation sequencing technologies, diversity of funding mechanisms, and differences across nations in regards to informed consent and/or sharing of samples across international boundaries are examples of issues that were considered by the committee and its working groups. The approach adopted by the planning teams has been to define a limited number of principles that are central to participation in the project, and provide recommendations to readers based on what is considered “best practices” at the time of writing this document. The authors attempted to discriminate essential from recommended principles using the terms “policy” and “guideline”.</p>
  <h2>
              	Qu\'est-ce qu\'une politique de consortium?</h2>
  <p>A consortium policy is a principle which consortium members agree to follow, during the course of the project. Although policies will likely be long-lasting, the Consortium will periodically review its policies.</p>
  <h2>
              	Qu\'est-ce qu\'une ligne directrice de consortium?</h2>
  <p>Consortium guidelines refer to recommendations made by Consortium working groups that offer advice as to what is believed to constitute “best practices” at a given time. Given the rapid evolution in technologies or new knowledge gleaned from the data generated by Consortium or other groups, it is expected that guidelines will evolve. It is also expected that approaches will need to vary based on tumor types, local laws, or other factors. In such cases, it is expected that Consortium members will be able to compare and explain differences in approaches, relative to Consortium guidelines. The Consortium has chosen to make most of its recommendations as guidelines rather than policies to allow flexibility in approaches and promote innovation. In this document, guidelines are often written in blue-shaded boxes. In this first document prepared by the Consortium, the authors strived to differentiate recommendations that are policy from those that are guidelines (even if some issues are clearly a mix of both). It is up to individual projects that join the Consortium to declare a clear plan, e.g., samples, criteria for being a sample, exons used, quality control, etc. Over time, the Consortium will generate best practices documents that will describe the current state-of-the-art, and propose modifications of the guidelines.</p>
  ',
          'safe_summary' => '',
        ),
      ),
    ),
  );

return $content;
}
