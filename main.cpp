// main.cpp: Martin Pfatrisch
// Description: Runs the main program for the challenge

#include <iostream>
#include <stdlib.h>

#define FREQUENCY 1

// struct Location: Structure to define a location with 3 coordinates
struct Location {
  int x;
  int y;
  int z;
};

struct Location generateLocation(void); // Function to generate a random location
void printLocation(struct Location l, int location_number); // Function to print the coordinates of a Location structure
int generateRandomNumber(int max_limit);

using namespace std;

/**
 * main: Main function
 * @return        Returns 0
 */
int main(void) {
  struct Location locations[10]; // Array of locations

  time_t start = time(0);

  srand(time(NULL)); // Initialize a random seed

  while(1) {
    if(time(0)-start == FREQUENCY) {
      // Assign coordinates to a Location in the locations arrays
      // Print the coordinates for each Location
      for (int i = 0; i < 10; i++) {
        locations[i] = generateLocation();
        printLocation(locations[i], i);
      }

      start = start + FREQUENCY;
    }
  }

  return 0;
}

/**
 * generateLocation: Function to generate a random coordinates for a Location
 * @return        Returns a Location structure with x, y, and z coordinates
 */
struct Location generateLocation(void) {
  struct Location l;

  l.x = generateRandomNumber(100);
  l.y = generateRandomNumber(100);
  l.z = generateRandomNumber(100);

  return l;
}

/**
 * printLocation: Function to print the coordinates of a Location structure
 * @param l       struct Location of which the coordinates should be printed out
 */
void printLocation(struct Location l, int location_number) {
  cout << "x" << location_number << " = " << l.x << "\ny" << location_number << " = " << l.y << "\nz" << location_number << " = " << l.z << endl;
}

/**
 * generateRandomNumber: Function to generate a random number
 * @param  max_limit Defines the upper limit for the random number
 * @return           Random number
 */
int generateRandomNumber(int max_limit) {
  int random_number;

  random_number = rand() % max_limit + 1;

  // Vector calculation with the maximum speed for a human beeing

  return random_number;
}
