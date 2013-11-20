<?php

/**
 * @file
 * Mica default data
 */

/**
 * Copied from profile standard_install.install
 */
function _mica_core_default_text_formats() {
  $filtered_html_format = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'weight' => 0,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML filter.
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
      ),
      // Line break filter.
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $filtered_html_format = (object) $filtered_html_format;
  filter_format_save($filtered_html_format);

  $full_html_format = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'weight' => 1,
    'filters' => array(
      // URL filter.
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
      ),
      // HTML corrector filter.
      'filter_htmlcorrector' => array(
        'weight' => 10,
        'status' => 1,
      ),
    ),
  );
  $full_html_format = (object) $full_html_format;
  filter_format_save($full_html_format);

  // Exported format: Bootstrap.
  $bootstrap_format = array(
    'format' => 'bootstrap',
    'name' => 'Bootstrap',
    'cache' => 1,
    'status' => 1,
    'weight' => 30,
    'filters' => array(),
  );
  $bootstrap_format = (object) $bootstrap_format;
  filter_format_save($bootstrap_format);

  return array(
    'filtered_html' => $filtered_html_format,
    'full_html' => $full_html_format,
    'bootstrap' => $bootstrap_format,
  );
}

/**
 * Insert default pre-defined node types into the database. For a complete
 * list of available node type attributes, refer to the node type API
 * documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
 *
 * Copied from profile standard_install.install
 */
function _mica_core_default_content_types() {
  $types = array(
    'page' => array(
      'type' => 'page',
      'name' => st('Basic page'),
      'base' => 'node_content',
      'description' => st("Use <em>basic pages</em> for your static content, such as an 'About us' page."),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
    ),
    'article' => array(
      'type' => 'article',
      'name' => st('Article'),
      'base' => 'node_content',
      'description' => st('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'custom' => 1,
      'modified' => 1,
      'locked' => 0,
    ),
  );
  foreach ($types as $name => $type) {
    $type = node_type_set_defaults($type);
    node_type_save($type);
    node_add_body_field($type);
    title_field_replacement_toggle('node', $name, 'title');
  }

  // Insert default pre-defined RDF mapping into the database.
  $rdf_mappings = array(
    array(
      'type' => 'node',
      'bundle' => 'page',
      'mapping' => array(
        'rdftype' => array('foaf:Document'),
      ),
    ),
    array(
      'type' => 'node',
      'bundle' => 'article',
      'mapping' => array(
        'field_image' => array(
          'predicates' => array('og:image', 'rdfs:seeAlso'),
          'type' => 'rel',
        ),
        'field_tags' => array(
          'predicates' => array('dc:subject'),
          'type' => 'rel',
        ),
      ),
    ),
  );
  foreach ($rdf_mappings as $rdf_mapping) {
    rdf_mapping_save($rdf_mapping);
  }

  // Create a default vocabulary named "Tags", enabled for the 'article' content type.
  $description = st('Use tags to group articles on similar topics into categories.');
  $help = st('Enter a comma-separated list of words to describe your content.');
  $vocabulary = (object) array(
    'name' => st('Tags'),
    'description' => $description,
    'machine_name' => 'tags',
    'help' => $help,

  );
  taxonomy_vocabulary_save($vocabulary);

  $field = array(
    'field_name' => 'field_' . $vocabulary->machine_name,
    'type' => 'taxonomy_term_reference',
    // Set cardinality to unlimited for tagging.
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
    'settings' => array(
      'allowed_values' => array(
        array(
          'vocabulary' => $vocabulary->machine_name,
          'parent' => 0,
        ),
      ),
    ),
  );
  field_create_field($field);

  $instance = array(
    'field_name' => 'field_' . $vocabulary->machine_name,
    'entity_type' => 'node',
    'label' => 'Tags',
    'bundle' => 'article',
    'description' => $vocabulary->help,
    'widget' => array(
      'type' => 'taxonomy_autocomplete',
      'weight' => -4,
    ),
    'display' => array(
      'default' => array(
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
  );
  field_create_instance($instance);

  // Create an image field named "Image", enabled for the 'article' content type.
  // Many of the following values will be defaulted, they're included here as an illustrative examples.
  // See http://api.drupal.org/api/function/field_create_field/7

  $field = array(
    'field_name' => 'field_image',
    'type' => 'image',
    'cardinality' => 1,
    'locked' => FALSE,
    'indexes' => array('fid' => array('fid')),
    'settings' => array(
      'uri_scheme' => 'public',
      'default_image' => FALSE,
    ),
    'storage' => array(
      'type' => 'field_sql_storage',
      'settings' => array(),
    ),
  );
  field_create_field($field);

  // Many of the following values will be defaulted, they're included here as an illustrative examples.
  // See http://api.drupal.org/api/function/field_create_instance/7
  $instance = array(
    'field_name' => 'field_image',
    'entity_type' => 'node',
    'label' => 'Image',
    'bundle' => 'article',
    'description' => st('Upload an image to go with this article.'),
    'required' => FALSE,
    'settings' => array(
      'file_directory' => 'field/image',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'alt_field' => TRUE,
      'title_field' => '',
    ),
    'widget' => array(
      'type' => 'image_image',
      'settings' => array(
        'progress_indicator' => 'throbber',
        'preview_image_style' => 'thumbnail',
      ),
      'weight' => -1,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'large', 'image_link' => ''),
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'image',
        'settings' => array('image_style' => 'medium', 'image_link' => 'content'),
        'weight' => -1,
      ),
    ),
  );
  field_create_instance($instance);
}

function _mica_core_default_variables() { // Default "Basic page" to not be promoted and have comments disabled.
  variable_set('node_options_page', array('status'));
  variable_set('comment_page', COMMENT_NODE_HIDDEN);

  // Don't display date and author information for "Basic page" nodes by default.
  variable_set('node_submitted_page', FALSE);

  // Enable user picture support and set the default to a square thumbnail option.
  variable_set('user_pictures', '1');
  variable_set('user_picture_dimensions', '1024x1024');
  variable_set('user_picture_file_size', '800');
  variable_set('user_picture_style', 'thumbnail');

  // Only administrators can create user accounts.
  variable_set('user_register', USER_REGISTER_ADMINISTRATORS_ONLY);
}

/**
 * Enable default permissions for system roles.
 * Copied from profile standard_install.install
 */
function _mica_core_default_permissions($filtered_html_permission) {
  user_role_grant_permissions(DRUPAL_ANONYMOUS_RID,
    array('access content', 'access comments', $filtered_html_permission));
  user_role_grant_permissions(DRUPAL_AUTHENTICATED_RID,
    array('access content', 'access comments', 'post comments', 'skip comment approval', $filtered_html_permission));

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();
}

/**
 * Copied from profile standard_install.install
 */
function _mica_core_default_admin_theme() { // Enable the admin theme.
  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', 'seven')
    ->execute();
  variable_set('admin_theme', 'seven');
}

function _mica_core_default_pages() {

  $home_content = file_get_contents(drupal_get_path('module', 'mica_core') . '/default_data/home.html');
  $home_page = mica_core_add_page(st('Mica'), st($home_content), 'home', 'bootstrap');
  mica_core_create_menu(st('Home'), '<front>', '', TRUE, FALSE, 0);
  variable_set('site_frontpage', 'node/' . $home_page->nid);

  $resources_page = mica_core_add_page(
    st('Resources'),
    st('This page aims to display the consortium resources offered to the scientific community. Two kinds of resource are currently offered with the Mica default configuration: the <a href="?q=datasets">consortium datasets</a> and the <a href="?q=documents">consortium documents</a>.'),
    'resources');
  mica_core_create_node_menu($resources_page, FALSE, TRUE, 10);

  $research_page = mica_core_add_page(
    st('Research'),
    st('This section aims to reflect the research activities generated by the consortium.'),
    'research');
  mica_core_create_node_menu($research_page, FALSE, TRUE, 30);

  $ABOUT_AND_HOME_TEXT = st('Welcome to Mica, a powerful software application used to create web portals for epidemiological study consortia.

Using Mica, consortia can build personalized web sites for publishing their research activities and their membership. Mica includes many domain-specific features such as study catalogues, data dictionary browsers, on-line data access request forms, community tools (forums, events, news) and others. Moreover, Mica includes a powerful data search engine that allows authenticated researchers to perform distributed queries on the content of each individual study data collection hosted by the OBiBa Opal database software (www.obiba.org).

Mica is based on the content management software Drupal (www.drupal.org) used by millions of websites worldwide. As such, a webmaster benefits from all the power and flexibility of Drupal, as well as the support of an extended developer community.

Installing a site with Mica demo profile will help to illustrate its functionalities. This may serve as a good starting point for customizing your web portal.');

  $about_page = mica_core_add_page(st('About'), $ABOUT_AND_HOME_TEXT, 'about');
  mica_core_create_node_menu($about_page, FALSE, FALSE, 50);

}