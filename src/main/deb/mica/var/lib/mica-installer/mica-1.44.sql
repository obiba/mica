DELETE FROM system WHERE name = 'mica_standard';

UPDATE variable
  SET value = 's:17:"mica_distribution";'
  WHERE name = 'install_profile';

UPDATE feeds_source
  SET config = 'a:2:{s:16:\"FeedsFileFetcher\";a:3:{s:3:\"fid\";s:0:\"\";s:6:\"source\";s:60:\"profiles/mica_distribution/data/field_description_import.csv\";s:6:\"upload\";s:0:\"\";}s:14:\"FeedsCSVParser\";a:2:{s:9:\"delimiter\";s:1:\";\";s:10:\"no_headers\";i:0;}}',
      source = 'profiles/mica_distribution/data/field_description_import.csv'
  WHERE id = 'csv_field_description_import';

TRUNCATE TABLE registry_file;

TRUNCATE TABLE cache;
TRUNCATE TABLE cache_bootstrap;
TRUNCATE TABLE cache_field;
TRUNCATE TABLE cache_filter;
TRUNCATE TABLE cache_form;
TRUNCATE TABLE cache_image;
TRUNCATE TABLE cache_menu;
TRUNCATE TABLE cache_page;
TRUNCATE TABLE cache_path;
TRUNCATE TABLE cache_token;
TRUNCATE TABLE cache_update;
TRUNCATE TABLE cache_views;
TRUNCATE TABLE cache_views_data;