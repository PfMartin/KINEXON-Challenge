// location_generator: Martin Pfatrisch
// Description: Creates and updates a location randomly

#include <iostream>
#include <random>
#include <chrono>
#include <thread>


const int xy_max = 100;   // Upper limit of x and y in meter
const int xy_min = 0;     // Lower limit of x and y in meter
const int z_max = 2.5;    // Upper Limit of z in meter
const int z_min = 0;      // Lower Limit of z in meter

// struct Location: Structure to define a location with 3 coordinates
struct Location {
  float x;
  float y;
  float z;
};

// Function to generate a random float using a uniform distribution
float get_rand_float_uni(float, float);
// Function to generate a random float using a normal distribution
float get_rand_float_norm(float, float);
// Function to generate a random location
struct Location init_loc(void);
// Funtion to update the location with random coordinates
struct Location update_loc(struct Location);
// Function to print the coordinates of a Location structure
void print_loc(struct Location, int);
// Function to add white noise to a Location
struct Location add_white_noise(struct Location);

/**
 * get_rand_float_uni: Function to generate a random float between 0 and a given maximum limit using a uniform distribution
 * @param   [float]   lower_limit   Defines the lower limit for the distribution
 * @param   [float]   upper_limit   Defines the upper limit for the distribution
 * @return  [float]   Returns the generated random float
 */
float get_rand_float_uni(float lower_limit, float upper_limit) {
  std::random_device rand_float;
  std::mt19937 generator(rand_float());
  std::uniform_real_distribution<float> distrib(lower_limit, upper_limit);

  return distrib(generator);
}

/**
 * get_rand_float_norm: Function to generate a random float between 0 and a given maximum limit using a normal distribution
 * @param   [float]   mu      Defines the mean for the distribution
 * @param   [float]   sigma   Defines the standard deviation for the distribution
 * @return  [float]   Returns the generated random float
 */
float get_rand_float_norm(float mu, float sigma) {
  std::random_device rand_float;
  std::mt19937 generator(rand_float());
  std::normal_distribution<float> distrib(mu, sigma); // mean, std deviation

  return distrib(generator);
}

/**
 * init_loc: Function to generate random coordinates for a Location
 *  * @return  [struct Location]  Returns a Location structure with x, y, and z coordinates
 */
struct Location init_loc(void) {
  struct Location loc;

  loc.x = get_rand_float_uni(xy_min, xy_max);
  loc.y = get_rand_float_uni(xy_min, xy_max);
  loc.z = get_rand_float_uni(z_min, z_max);

  return loc;
}

/**
 * update_loc: Function to update the location by adding or substacting a random float
 * @param   [struct Location]   loc   Location, that should be updated
 * @return  [struct Location]   Returns the new location
 */
struct Location update_loc(struct Location loc) {
  const float max_dist = 8.76;      // Maximum distance in 1 second in meter
  float new_loc_x = loc.x + get_rand_float_uni(-max_dist, max_dist);
  float new_loc_y = loc.y + get_rand_float_uni(-max_dist, max_dist);
  float new_loc_z = loc.z + get_rand_float_uni(-z_max, z_max);

  if(new_loc_x < xy_min) {
    loc.x = xy_min;
  } else if(new_loc_x > xy_max) {
    loc.x = xy_max;
  } else {
    loc.x = new_loc_x;
  }

  if(new_loc_y < xy_min) {
    loc.y = xy_min;
  } else if(new_loc_y > xy_max) {
    loc.y = xy_max;
  } else {
    loc.y = new_loc_y;
  }

  if(new_loc_z < z_min) {
    loc.z = z_min;
  } else if(new_loc_z > z_max) {
    loc.z = z_max;
  } else {
    loc.z = new_loc_z;
  }

  loc = add_white_noise(loc);

  return loc;
}

/**
 * print_loc: Function to print the coordinates of a Location structure
 * @param   [struct Location]   loc   Location of which the coordinates should be printed out
 */
void print_loc(struct Location loc, int loc_nr) {
  std::cout
    << "Location Sensor " << loc_nr << ": \n"
    << "x" << loc_nr << " = " << loc.x
    << " | y" << loc_nr << " = " << loc.y
    << " | z" << loc_nr << " = " << loc.z
    << std::endl;
};

/**
 * add_white_noise: Function to add white noise to a Location structure
 * @param   [struct Location]   loc   Location the white noise should be added to
 * @return     [description]
 */
struct Location add_white_noise(struct Location loc) {
  const float mu = 0;
  const float sigma = 0.01;

  loc.x = loc.x + get_rand_float_norm(mu, sigma);
  loc.y = loc.y + get_rand_float_norm(mu, sigma);
  loc.z = loc.z + get_rand_float_norm(mu, sigma);

  return loc;
}
