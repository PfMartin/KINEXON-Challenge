// main.cpp: Martin Pfatrisch
// Description: Runs the main program for the challenge

#include <iostream>
#include <random>
#include <chrono>
#include <thread>

#define     PERIOD          1000      // Cycle duration in milliseconds
#define     SPEED_MAX       12.4      // Maximum distance in 1 second in meters
#define     LOC_MAX         100       // Upper limit of x and y
#define     LOC_MIN         0         // Lower limit of x and y

// struct Location: Structure to define a location with 3 coordinates
struct Location {
  float x;
  float y;
  float z;
};
// Function to generate a random float
float get_rand_float(float upper_limit);
// Function to generate a random location
struct Location init_loc(void);
// Funtion to update the location with random coordinates
struct Location update_loc(struct Location loc);
// Function to print the coordinates of a Location structure
void print_loc(struct Location l, int loc_nr);

/**
 * main: Main function
 * @return      [int]       0
 */
int main(void) {
  // Array of locations
  struct Location locs[10];

  // Initialize locations
  for(int i = 0; i < 10; i++) {
    locs[i] = init_loc();
  }

  while(1) {
    locs[0] = update_loc(locs[0]);
    print_loc(locs[0], 0);
    // for(int i = 0; i < 10; i++) {
    //   locs[i] = update_loc();
    //   print_loc(locs[i], i);
    // }

    std::this_thread::sleep_for(std::chrono::milliseconds(PERIOD));
  }

  return 0;
}

/**
 * get_rand_float: Function to generate a random float between 0 and a given maximum limit using a uniform distribution
 * @param   [float]   upper_limit   Defines the upper limit for the distribution
 * @return  [float]   Returns the generated random float
 */
float get_rand_float(float lower_limit, float upper_limit) {
  std::random_device rand_float;
  std::mt19937 generator(rand_float());
  std::uniform_real_distribution<float> distrib(lower_limit, upper_limit);

  return distrib(generator);
}

/**
 * init_loc: Function to generate random coordinates for a Location
 *  * @return  [struct Location]  Returns a Location structure with x, y, and z coordinates
 */
struct Location init_loc(void) {
  struct Location loc;

  loc.x = get_rand_float(LOC_MIN, LOC_MAX);
  loc.y = get_rand_float(LOC_MIN, LOC_MAX);
  loc.z = get_rand_float(LOC_MIN, LOC_MAX);

  return loc;
}

/**
 * update_loc: Function to update the location by adding or substacting a random float
 * @param   [struct Location]   loc   Location, that should be updated
 * @return  [struct Location]   Returns the new location
 */
struct Location update_loc(struct Location loc) {
  float dist_low_x; // Distance to upper limit of x
  float dist_up_x;  // Distance to lower limit of x
  float dist_low_y; // Distance to upper limit of y
  float dist_up_y;  // Distance of lower limit of y

  dist_low_x = LOC_MIN + loc.x;
  dist_up_x = LOC_MAX - loc.x;
  dist_low_y = LOC_MIN + loc.y;
  dist_up_y = LOC_MAX - loc.y;

  loc.x = loc.x + get_rand_float(-dist_low_x, dist_up_x);
  loc.y = loc.y + get_rand_float(-dist_low_y, dist_up_y);
  // loc.z = loc.z + get_rand_float(-30, 30);

  return loc;
}

/**
 * print_loc: Function to print the coordinates of a Location structure
 * @param loc       struct Location of which the coordinates should be printed out
 */
void print_loc(struct Location loc, int loc_nr) {
  std::cout
    << "Location Sensor " << loc_nr << ": \n"
    << "x" << loc_nr << " = " << loc.x
    << " | y" << loc_nr << " = " << loc.y
    << " | z" << loc_nr << " = " << loc.z
    << std::endl;
}
