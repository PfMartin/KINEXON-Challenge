# KINEXON C++ Challenge

This is a git repository for taking the KINEXON C++ Challenge. The file contains the description of the challenge, as well as the documentation regarding the project files.

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

## build

All executables for running the programm are located in the folder `build`. Here the executable `server` starts the server, which listens to data from the sent by the executable `clients`. In order to start the communication it is recommended to start the server first and afterwards the clients.

## distribution_graphs

The folder `distribution_graphs` contains a poetry project to draw distribution graphs related with the position generator. Since multiple random data is generated in the position generator, the python script `distribution_graphs.py` helps with visualizing the possible values for each normal distribution.

#### Setup

The dependencies for the script are managed by the package `poetry`, which makes it easy to share dependencies between developers. Just install poetry with `pip install poetry` and apply the dependencies defined in `poetry.lock` to your local repository with `poetry install`.

#### distribtion_graphs.py

This script draws 4 histograms for normal distributions. These histograms visualize the normal distributions for the following random number generations:

- Update of a sensor position's x- and y-values
- Noise added to each coordinate of the sensor position
- Initialization of a sensor position's z-value
- Update of a sensor position's z-value

For each normal distribution an instance of the class `NormalDistribution` is initialized. Afterwards the class' method `plotHistogram`, which draws the histogram using the package `matplotlib`, is called.

By tinkering with the initialization parameters for each normal distribution the output values can be fitted to the real world scenario as closely as possible.

## include

#### position_generator.h

#### position.pb.h

## src

#### Makefile

#### position.proto

#### clients

#### server

## Assumptions

# position_generator.h

## Versionen

| Datum      | Mitarbeiter | Version | Änderung                                                                                            |
| ---------- | ----------- | ------- | --------------------------------------------------------------------------------------------------- |
| 2021-05-25 | Martin      | 1.0     | Initiale Erstellung                                                                                 |
| 2021-06-30 | Martin      | 1.1     | Genauere Beschreibung bei manchen Punkten                                                           |
| 2021-07-28 | Martin      | 1.2     | KDE-Wallet-Einstellungen entfernt, da sie nicht benötigt werden und Änderungen bei Benutzer anlegen |

## getPosNeg

This function Returns a randomly 1 or -1. For that, it defines a random integer with `random()` and compares its bit representation with the bit representation of the integer 2. The result of this comparison is either 2 or 0. Following table shows the comparison of the bit representation for 1 - 12 with 2.

| int | bit representation | result bit representation | result int |
| --- | -----------------: | ------------------------: | ---------- |
| 2   |                 10 |                        10 | 2          |
| 3   |                 11 |                        10 | 2          |
| 4   |                100 |                       000 | 0          |
| 5   |                101 |                       000 | 0          |
| 6   |                110 |                       010 | 2          |
| 7   |                111 |                       010 | 2          |
| 8   |               1000 |                      0000 | 0          |
| 9   |               1001 |                      0000 | 0          |
| 10  |               1010 |                      0010 | 2          |
| 11  |               1011 |                      0010 | 2          |
| 12  |               1100 |                      0000 | 0          |
| ... |                ... |                       ... | ...        |

Further, the 1 is substracted from the comparison, which results in either 1 or -1.

## getRandFloatUni

This function returns a random float, which is derived from a uniform distribution. The generation is done by `std::mt19937`, where the input parameters of the function define the upper limit and the lower limit of the uinform distribution.

## getRandFloatNorm

This function returns a random float, which is derived from a normal distribution. The generation is done by `std::mt19937`, where the input paramters of the function define the mean and the standard deviation of the normal distribution.

## initPosition

This function returns a position after initializing it with random coordinates. While x- and y-coordinates are initialized with random floats derived from a uniform distribution, the z-coordinate is initialized with a random float using a normal distribution. The mean for the z-coordinate is chosen by assuming that the sensor is located at the height of the players neck.

## updatePosition

This function updates the input position from the function's parameters with a random coordinates and returns the updated position, while considering the maximum velocity of a human beeing.

#### Calculation of x-/y-coordinates

A random float is generated using a normal distribution, considering the maximum velocity. This random float is then singed or unsigned added to the initial coordinate of the passed position. Whether the random float is singed or unsigned is calculated randomly with a uniform distribution.

It was assumed, that the maximum velocity of a human player is 44.72 km/h (olympics.com). This means the maximum distance a human being could travel in 1 second is about 12.42 m. Therefore, the maximum length of the vector int the x-/y-dimension is 12.42. Knowing the maximum vector length, the maximum change of each coordinate in a 2-dimensional space can be calculated as follows:

IMAGE!

#### Calculation of the z-coordinate

There is no velocity limit for the z-coordinate. Therefore, this coordinate is calculated randomly using a normal distribution and set as the new z-coordinate of the passed position.

## addWhiteNoise


<div style='text-align: center'>
<img title="Vector Calculation Formula" alt="Vector Calculation Formula" src="./images/Vector_calculation.svg">
</div>
