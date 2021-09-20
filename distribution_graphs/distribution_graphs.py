# distributions.py: Martin Pfatrisch
# Description: The program draws 4 normal distribution graphs for distributions used in the location generator

import numpy as np
import matplotlib.pyplot as plt

# NormalDistribution: Defines Information for a normal distribution
# @param    [number]        targetMean  Defines the targeted mean for the distribution
# @param    [number]        targetSigma   Defines the targeted standard deviation for the distribution
# @param    [string]        title       Title to be set for the histogram
class NormalDistribution:
    def __init__(self, targetMean, targetSigma, title):
        self.type = type
        self.mean = targetMean
        self.std = targetSigma
        self.title = title
        self.values = self.calculateValues()

    # calculateValues: Calculates values for the distribution to plot
    def calculateValues(self):
        values = np.random.normal(self.mean, self.std, 1000000)

        return values

    # plotHistogram: Plots a histogram based on a given distribution
    # @param    [integer]       subPlotNr   Defines the subplot number
    def plotHistogram(self, subPlotNr):
        actualMean = np.mean(self.values)
        actualStd = np.std(self.values)

        limitLineFormat = {
            'color': 'silver',
            'linestyle': 'dashed',
            'linewidth': 1
        }

        meanLineFormat = {
            'color': 'black',
            'linestyle': 'solid',
            'linewidth': 1,
        }

        plot = plt.subplot(2, 2, subPlotNr)
        plot.set_title(self.title)
        plot.hist(self.values, 1000, color='darkturquoise')
        plot.set_xlabel('Values')
        plot.set_ylabel('Frequency')

        # Show lines at 3 std from the mean in both directions
        plot.axvline(actualMean + actualStd * 3, **limitLineFormat)
        plot.axvline(actualMean - actualStd * 3, **limitLineFormat)
        plot.axvline(actualMean + actualStd * 2, **limitLineFormat)
        plot.axvline(actualMean - actualStd * 2, **limitLineFormat)
        plot.axvline(actualMean + actualStd, **limitLineFormat)
        plot.axvline(actualMean - actualStd, **limitLineFormat)
        plot.axvline(actualMean, **meanLineFormat)

        xTicks = [actualMean - actualStd * 3, actualMean - actualStd * 2, actualMean - actualStd, actualMean, actualMean + actualStd, actualMean + actualStd * 2, actualMean + actualStd * 3]
        plot.set_xticks(xTicks)
        plot.set_xlim([actualMean - np.std(self.values) * 4, actualMean + np.std(self.values) * 4])

def main():
    maxDist = 8.76
    muXY = maxDist / 2
    muZ = 1.65
    sigmaZInit = 0.05
    sigmaZUpdate = 0.3

    muNoise = 0
    sigmaNoise = 0.01


    xyUpdate = NormalDistribution(muXY, maxDist / 6, 'Normal Distribution for Updating X or Y coordinates')
    noise = NormalDistribution(muNoise, sigmaNoise, 'Normal Distribution for white noise')
    zInit = NormalDistribution(muZ, sigmaZInit, 'Normal Distribution for the Initialization of Z')
    zUpdate = NormalDistribution(muZ, sigmaZUpdate, 'Normal Distribution for Updating Z')

    xyUpdate.plotHistogram(1)
    noise.plotHistogram(2)
    zInit.plotHistogram(3)
    zUpdate.plotHistogram(4)

    plt.show()

if __name__ == '__main__':
    main()
