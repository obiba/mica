Mica i18n
------------------------

Configure Mica internationalization.


INSTALLATION
------------------------

To have Mica in another language than english, follow these steps:

- Enable the module "Mica_i18n" at /admin/modules

- Add a language from the page /admin/config/regional/language (for now, Mica modules support french and english
  translations, for any other language, you will have to translate those modules in you own language)

- If needed, configure Language field position for each content type (admin/structure/types).

- Go to Search API administration page (admin/config/search/search_api/index) and click Save on each indexes field list.
  Then clear & re-index each indexes.
  See http://jira.obiba.org/jira/browse/MICA-624

- To enable translation of a content type title, edit content type and replace the title by a field instance.


KNOWN ISSUES:
------------------------

- Noderef_create does not work with i18n stuff


------------------------
This project is sponsored by OBiBa [http://www.obiba.org].
OBiBa is a collaborative international project whose mission is to build high-quality open source software for biobanks.