Mica Relation
------------------------

The entry point/portal of a study in the Consortium website is a content of type Study.
As information about a Study can be quite large and of different nature, apart of the Study content-type, one would expect
to be able to split information into contents of different types that would be related to their parent content of type Study.
One would also like to index this information in a search engine and look for Study that match criteria on related content.

Mica provides provides such a relational mechanism:

* Define a parent-child relation between any content-types (e.g. Study being the parent and Study Information being the child for example),
* Create/delete a content of type Study will cascade creation/deletion of child contents and link them together using references.


------------------------
This project is sponsored by OBiBa [http://www.obiba.org].
OBiBa is a collaborative international project whose mission is to build high-quality open source software for biobanks.