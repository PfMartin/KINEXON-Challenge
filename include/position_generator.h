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

// A new value is assigned to these variables when the corresponding function is called
int sign;
float randFloat;

// Prototypes for created functions
void getPosNeg(int&);
void getRandFloatUni(float&, float, float);
void getRandFloatNorm(float&, float, float);
struct Data3d initPosition(void);
struct Data3d updatePosition(struct Data3d);
struct Data3d addWhiteNoise(struct Data3d);

/**
 * getPosNeg: Function to generate either -1 or 1 depending on the binary value of the random number. In case the second bit is set the generated value is 1. In case it's not set, the generated value is -1.
 * @param   [int&]    intToUpdate   Reference to the integer that should be updated
 */
void getPosNeg(int& intToUpdate) {
  intToUpdate = (random() & 2) - 1;
}

/**
 * getRandFloatUni: Function to generate a random float between a given lower limit and a given upper limit using a uniform distribution. It updates float randFloat with the generated value.
 * @param   [float&]  floatToUpdate   Reference to the float that should be updated
 * @param   [float]   lowerLimit      Defines the lower limit for the distribution
 * @param   [float]   upperLimit      Defines the upper limit for the distribution
 */
void getRandFloatUni(float& floatToUpdate, float lowerLimit, float upperLimit) {
  std::random_device random;
  std::mt19937 generator(random());
  std::uniform_real_distribution<float> distrib(lowerLimit, upperLimit);

  floatToUpdate = distrib(generator);
}

/**
 * getRandFloatNorm: Function to generate a random float using a normal distribution. It updates float randFloat with the generated value.
 * @param   [float&]  floatToUpdate Reference to the float that should be updated
 * @param   [float]   mu            Defines the mean for the distribution
 * @param   [float]   sigma         Defines the standard deviation for the distribution
 */
void getRandFloatNorm(float& floatToUpdate, float mu, float sigma) {
  std::random_device random;
  std::mt19937 generator(random());
  std::normal_distribution<float> distrib(mu, sigma); // mean, std deviation

  floatToUpdate = distrib(generator);
}

/**
 * initPosition: Function to generate random coordinates for a Position
 *  * @return  [struct Data3d]  Returns a Position structure with x, y, and z coordinates
 */
struct Data3d initPosition(void) {
  const float zStd = 0.05;
  struct Data3d data3d;

  getRandFloatUni(randFloat, xyMin, xyMax);
  data3d.x = randFloat;

  getRandFloatUni(randFloat, xyMin, xyMax);
  data3d.y = randFloat;

  getRandFloatUni(randFloat, xyMin, xyMax);
  data3d.z = randFloat;

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
  getPosNeg(sign);
  getRandFloatNorm(randFloat, maxDist / 2, maxDist / 6);
  data3d.x = data3d.x + sign * randFloat;

  getPosNeg(sign);
  getRandFloatNorm(randFloat, maxDist / 2, maxDist / 6);
  data3d.y = data3d.y + sign * randFloat;

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
  getRandFloatNorm(randFloat, zMean, zStd);
  data3d.z = randFloat;

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

  getRandFloatNorm(randFloat, mu, sigma);
  data3d.x = data3d.x + randFloat;

  getRandFloatNorm(randFloat, mu, sigma);
  data3d.y = data3d.y + randFloat;

  getRandFloatNorm(randFloat, mu, sigma);
  data3d.z = data3d.z + randFloat;

  return data3d;
}

#endif // POSITION_GENERATOR_H
