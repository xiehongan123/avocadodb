

@brief looks up a document
`collection.document(document)`

The *document* method finds a document given its identifier or a document
object containing the *_id* or *_key* attribute. The method returns
the document if it can be found.

An error is thrown if *_rev* is specified but the document found has a
different revision already. An error is also thrown if no document exists
with the given *_id* or *_key* value.

Please note that if the method is executed on the avocadod server (e.g. from
inside a Foxx application), an immutable document object will be returned
for performance reasons. It is not possible to change attributes of this
immutable object. To update or patch the returned document, it needs to be
cloned/copied into a regular JavaScript object first. This is not necessary
if the *document* method is called from out of avocadosh or from any other
client.

`collection.document(document-handle)`

As before. Instead of document a *document-handle* can be passed as
first argument.

*Examples*

Returns the document for a document-handle:

@EXAMPLE_AVOCADOSH_OUTPUT{documentsCollectionName}
~ db._create("example");
~ var myid = db.example.insert({_key: "2873916"});
  db.example.document("example/2873916");
~ db._drop("example");
@END_EXAMPLE_AVOCADOSH_OUTPUT

An error is raised if the document is unknown:

@EXAMPLE_AVOCADOSH_OUTPUT{documentsCollectionNameUnknown}
~ db._create("example");
~ var myid = db.example.insert({_key: "2873916"});
| db.example.document("example/4472917");
~     // xpError(ERROR_AVOCADO_DOCUMENT_NOT_FOUND)
~ db._drop("example");
@END_EXAMPLE_AVOCADOSH_OUTPUT

An error is raised if the handle is invalid:

@EXAMPLE_AVOCADOSH_OUTPUT{documentsCollectionNameHandle}
~ db._create("example");
  db.example.document(""); // xpError(ERROR_AVOCADO_DOCUMENT_HANDLE_BAD)
~ db._drop("example");
@END_EXAMPLE_AVOCADOSH_OUTPUT

