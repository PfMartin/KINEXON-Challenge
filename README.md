# KINEXON C++ Challenge

This is a git repository for taking the KINEXON C++ Challenge. The file contains the description of the challenge, as well as the documentation regarding the project files.

## Challenge description

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

## Project structure

#### build

All executables for running the programm are located in the folder `build`. Here the executable `server` starts the server, which listens to data from the sent by the executable `clients`. In order to start the communication it is recommended to start the server first and afterwards the clients.

#### distribution_graphs

The folder `distribution_graphs` contains a poetry project to draw distribution graphs related with the position generator. Since multiple random data is generated in the position generator, the python script `distribution_graphs.py` helps with visualizing the possible values for each normal distribution.

The dependencies for the script are managed by the package `poetry`, which makes it easy to share dependencies between developers. Just install poetry with `pip install poetry` and apply the dependencies defined in `poetry.lock` to your local repository with `poetry install`.

#### documentation

In `documentation` the source code is documented in several files. Here, explanations about the chosen values and the functions in general can be found.

## include

This folder contains header files, which contain useful functions for `clients.cpp` and `server.cpp`. These header files are include in `clients.cpp` or `server.cpp` or both.

## src

`src` contains the source files that need to be compiled, as well as instructions on how to compile them in the `Makefile`.
