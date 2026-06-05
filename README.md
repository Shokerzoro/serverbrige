# uniter-messaging

Messaging helpers for Uniter request creation, one-way events, and local direct-response tracking.

`MessageManager` is a QObject singleton that owns local monotonic `sequence_id` generation for `QueryMessage` and emits outgoing `UniterMessage` instances through `signalSendMessage`.

Use `QueryMessage` subclasses for direct request/response traffic. Use `EventMessage` subclasses for one-way messages that should be sent without response tracking.

Specialized messages live in `specializedmessages.h`: CRUD query/event messages, transaction queries, and MinIO file queries.
