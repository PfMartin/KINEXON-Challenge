// position_generator.h: Martin Pfatrisch
// Description: Creates and updates a position randomly
#ifndef POSITION_GENERATOR_H
#define POSITION_GENERATOR_H

#include <iostream>
#include <random>
#include <chrono>
#include <thread>


const int xyMax = 100;   // Upper limit of x and y in meter
const int xyMin = 0;     // Lower limit of x and y in meter
const float zMean = 1.65;  // Average height of the sensor in meter

// struct Data3d: Structure to define a position with 3 coordinates
struct Data3d {
  float x;
  float y;
  float z;
};

// Prototypes for created functions
int getPosNeg();
float getRandFloatUni(float, float);
float getRandFloatNorm(float, float);
struct Data3d initPosition(void);
struct Data3d updatePosition(struct Data3d);
struct Data3d addWhiteNoise(struct Data3d);

/**
 * getPosNeg: Function to return either -1 or 1 depending on the binary value of the random number. In case the second bit is set the function returns 1. In case it's not set, the function returns -1
 * @return  [integer]   Returns either 1 or -1
 */
int getPosNeg() {
  return (random() & 2) - 1;
}

/**
 * getRandFloatUni: Function to generate a random float between 0 and a given maximum limit using a uniform distribution
 * @param   [float]   lowerLimit   Defines the lower limit for the distribution
 * @param   [float]   upperLimit   Defines the upper limit for the distribution
 * @return  [float]   Returns the generated random float
 */
float getRandFloatUni(float lowerLimit, float upperLimit) {
  std::random_device randFloat;
  std::mt19937 generator(randFloat());
  std::uniform_real_distribution<float> distrib(lowerLimit, upperLimit);

  return distrib(generator);
}

/**
 * getRandFloatNorm: Function to generate a random float between 0 and a given maximum limit using a normal distribution
 * @param   [float]   mu      Defines the mean for the distribution
 * @param   [float]   sigma   Defines the standard deviation for the distribution
 * @return  [float]   Returns the generated random float
 */
float getRandFloatNorm(float mu, float sigma) {
  std::random_device randFloat;
  std::mt19937 generator(randFloat());
  std::normal_distribution<float> distrib(mu, sigma); // mean, std deviation

  return distrib(generator);
}

/**
 * initPosition: Function to generate random coordinates for a Position
 *  * @return  [struct Data3d]  Returns a Position structure with x, y, and z coordinates
 */
struct Data3d initPosition(void) {
  const float zStd = 0.05;
  struct Data3d data3d;

  data3d.x = getRandFloatUni(xyMin, xyMax);
  data3d.y = getRandFloatUni(xyMin, xyMax);
  data3d.z = getRandFloatNorm(zMean, zStd);

  return data3d;
}

/**
 * updatePosition: Function to update the position by adding or substacting a random float
 * @param   [struct Data3d]   data3d   Position, that should be updated
 * @return  [struct Data3d]   Returns the new position
 */
struct Data3d updatePosition(struct Data3d data3d) {
  const float maxDist = 8.76;      // Maximum distance in 1 second in meter
  const float zStd = 0.3;

  // Update coordinates
  data3d.x = data3d.x + getPosNeg() * getRandFloatNorm(maxDist / 2, maxDist / 6);
  data3d.y = data3d.y + getPosNeg() * getRandFloatNorm(maxDist / 2, maxDist / 6);

  // Check limits for x coordinate
  if(data3d.x < xyMin) {
    data3d.x = xyMin;
  } else if(data3d.x > xyMax){
    data3d.x = xyMax;
  }

  // Check limits for y coordinate
  if(data3d.y < xyMin) {
    data3d.y = xyMin;
  } else if(data3d.y > xyMax){
    data3d.y = xyMax;
  }

  // z can be calculated directly since there is no speed limit
  data3d.z = getRandFloatNorm(zMean, zStd);

  // Add white noise to the data3d
  data3d = addWhiteNoise(data3d);

  return data3d;
}

/**
 * addWhiteNoise: Function to add white noise to a Position structure
 * @param   [struct Data3d]   data3d   Position the white noise should be added to
 * @return  [struct Data3d]   Returns the new position
 */
struct Data3d addWhiteNoise(struct Data3d data3d) {
  const float mu = 0;
  const float sigma = 0.01;

  data3d.x = data3d.x + getRandFloatNorm(mu, sigma);
  data3d.y = data3d.y + getRandFloatNorm(mu, sigma);
  data3d.z = data3d.z + getRandFloatNorm(mu, sigma);

  return data3d;
}

#endif // POSITION_GENERATOR_H
