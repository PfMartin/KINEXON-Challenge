# distribution_graphs.py

## Versions

| Date       | Author           | Version | Modification   |
| ---------- | ---------------- | ------- | -------------- |
| 2021-09-20 | Martin Pfatrisch | 1.0     | Initialization |

## General description

This script draws 4 histograms for normal distributions. These histograms visualize the normal distributions for the following random number generations:

- Update of a sensor position's x- and y-values
- Noise added to each coordinate of the sensor position
- Initialization of a sensor position's z-value
- Update of a sensor position's z-value

For each normal distribution an instance of the class `NormalDistribution` is initialized. Afterwards the class' method `plotHistogram`, which draws the histogram using the package `matplotlib`, is called.

By tinkering with the initialization parameters for each normal distribution the output values can be fitted to the real world scenario as closely as possible.
