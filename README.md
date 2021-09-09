# KINEXON C++ Challenge

This is a git repository for taking the KINEXON C++ Challenge. The file contains the description of the challenge, as well is the documentation of the project structure.

## Description

This challenge is part of the job interview process for a position that includes C++ programming at KINEXON. It gives you the opportunity to show us how you approach programming problems and what we can expect from your code in terms of structure, efficiency and style.

We'd like you to build a small program that generates and publishes position data.<br>
The requirements are as follows.

A position data message consists of a timestamp, a sensor id and x/y/z coordinates. Positions shall be generated for 10 sensors with 1Hz. The positions should resemble movement on a playing field, i.e., they should not exceed velocities possible for human players and remain between 0 and 100m for x and y. After a position has been generated, noise of +/-30cm shall be added before the data leaves the position generator.

Positions are published via ZeroMQ as Protocol Buffers message, defined as follows:

```c++
message Data3d {
  required float x = 1;
  required float y = 2;
  required float z = 3;
}
```

```c++
message GeneratedPosition {
  required uint64 sensorId = 1;
  required uint64 timestamp_usec = 2;
  required Data3d position = 3;
}
```
