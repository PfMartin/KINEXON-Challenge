# position.proto

## Versions

| Date       | Author           | Version | Modification   |
| ---------- | ---------------- | ------- | -------------- |
| 2021-09-20 | Martin Pfatrisch | 1.0     | Initialization |

## Data3d

Data3d defines a proto message with three properties. Those illustrate the coordinates of a position in three dimensional space. Each of the coordinates is initialized with an unique float. All three are required for the successful initialization of the message.

## GeneratedPosition

GenereatedPosition defines a nested proto message with three properties. The first two properties illustrate the identifier of the sensor and a timestamp of the time when the sensor measured the data in the third property. Both properties are initialized using an unique unsinged integer of 64bit size. The third property is Data3d message, which was declared before. All three properties are required for the successful initialization of the message.
