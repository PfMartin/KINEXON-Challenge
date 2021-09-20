# clients.cpp

## Versions

| Date       | Author           | Version | Modification   |
| ---------- | ---------------- | ------- | -------------- |
| 2021-09-20 | Martin Pfatrisch | 1.0     | Initialization |

## setPosition

This functions returns an initialized proto message GeneratedPosition. It takes the properties of an updated struct Data3d and sets the properties of the proto message to those values. Furthermore, it passed the sensor id and a timestamp to the proto message. After that the proto message is initialized.

## serializeMessage

This function returns a zmq message with data serialized from the passed proto message GeneratedPosition. First of all it checks, whether the passed proto message has been initialized. After that, it creates the zmq message with data from the proto message and its size.

## main

First of all a zmq push socket for sending data is created. This socket is then bound to a host and a port. In the foor-loop 10 positions are initialized with random data, each position's data is passed to a proto message and serialized into a zmq message. This zmq message is then sent. Then the program waits for the defined period of time.

In the infinite while-loop the 10 positions are update with new random data, again passed to a proto message and serialized into a zmq message. Afterwards, this zmq message is sent.

Until the program is stopped, it continues to perform the aforementioned actions in an interval of the defined period of time.
