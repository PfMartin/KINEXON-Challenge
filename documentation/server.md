# server.cpp

## Versions

| Date       | Author           | Version | Modification   |
| ---------- | ---------------- | ------- | -------------- |
| 2021-09-20 | Martin Pfatrisch | 1.0     | Initialization |

## main

First of all, a pull socket for receiving data is created. This socket then connects to the same host and port as the clients' socket.
After a proto message is sent, the server receives the message and parses it back into a proto message. This data of this proto message is then printed to the console.
