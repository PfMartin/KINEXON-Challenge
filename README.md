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

## Asumptions

#### Maximum Velocity

It was assumed, that the maximum velocity of a human player is 44.72 km/h ([olympics.com](https://olympics.com/en/featured-news/usain-bolt-record-world-champion-athlete-fastest-man-olympics-sprinter-100m-200m)). This means the maximum distance a human being could travel in 1 second is about 12.42 m. Therefore, the maximum length of the vector, which is calculated every second is 12.42. Knowing the maximum vector length the maximum change of each coordinate in a 2-dimensional space can be calculated as follows:

<div style="text-align: center" >
<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{multline}\\&space;|\bar{a}|&space;=&space;\sqrt{a_{x}^{2}&space;&plus;&space;a_{y}^{2}}\\\\&space;a_{x}&space;=&space;a_{y}=a\\\\&space;|\bar{a}|_{max}&space;=&space;\sqrt{a^{2}&space;&plus;&space;a^{2}}\\\\&space;|\bar{a}|_{max}&space;=&space;\sqrt{2}\cdot&space;a\\\\&space;a&space;=&space;\frac{|\bar{a}|_{max}}{\sqrt{2}}&space;\end{multline}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{multline}\\&space;|\bar{a}|&space;=&space;\sqrt{a_{x}^{2}&space;&plus;&space;a_{y}^{2}}\\\\&space;a_{x}&space;=&space;a_{y}=a\\\\&space;|\bar{a}|_{max}&space;=&space;\sqrt{a^{2}&space;&plus;&space;a^{2}}\\\\&space;|\bar{a}|_{max}&space;=&space;\sqrt{2}\cdot&space;a\\\\&space;a&space;=&space;\frac{|\bar{a}|_{max}}{\sqrt{2}}&space;\end{multline}" title="\begin{multline}\\ |\bar{a}| = \sqrt{a_{x}^{2} + a_{y}^{2}}\\\\ a_{x} = a_{y}=a\\\\ |\bar{a}|_{max} = \sqrt{a^{2} + a^{2}}\\\\ |\bar{a}|_{max} = \sqrt{2}\cdot a\\\\ a = \frac{|\bar{a}|_{max}}{\sqrt{2}} \end{multline}" /></a>
</div>
