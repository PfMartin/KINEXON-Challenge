// main.cpp: Martin Pfatrisch
// Description: Runs the main program for the challenge

#include <iostream>
#include <stdlib.h>

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
  int interval = 1; // Frequency 1 Hz

  time_t start = time(0);

  // Initialize random seed
  srand(time(NULL));

  while(1) {
    if(time(0)-start == interval) {
      struct Location l1 = generateLocation();
      struct Location l2 = generateLocation();
      struct Location l3 = generateLocation();
      struct Location l4 = generateLocation();
      struct Location l5 = generateLocation();
      struct Location l6 = generateLocation();
      struct Location l7 = generateLocation();
      struct Location l8 = generateLocation();
      struct Location l9 = generateLocation();
      struct Location l10 = generateLocation();

      printLocation(l1, 1);
      printLocation(l2, 2);
      printLocation(l3, 3);
      printLocation(l4, 4);
      printLocation(l5, 5);
      printLocation(l6, 6);
      printLocation(l7, 7);
      printLocation(l8, 8);
      printLocation(l9, 9);
      printLocation(l10, 10);

      start = start + interval;
    }
  }

  return 0;
}

/**
 * generateLocation: Function to generate a random location
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

  return random_number;
}
