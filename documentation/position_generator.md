# position_generator.h

## Versions

| Date       | Author           | Version | Modification   |
| ---------- | ---------------- | ------- | -------------- |
| 2021-09-20 | Martin Pfatrisch | 1.0     | Initialization |

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

<div style='text-align: center'>
<img title="Vector Calculation Formula" alt="Vector Calculation Formula" src="../images/Vector_calculation.svg">
</div>

#### Calculation of the z-coordinate

There is no velocity limit for the z-coordinate. Therefore, this coordinate is calculated randomly using a normal distribution and set as the new z-coordinate of the passed position.

## addWhiteNoise
