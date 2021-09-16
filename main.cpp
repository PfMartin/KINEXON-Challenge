// main.cpp: Martin Pfatrisch
//

#include "location_generator.h"


// Function in location_generator.h to generate a random location
struct Location init_loc(void);
// Funtion in location_generator.h to update the location with random coordinates
struct Location update_loc(struct Location);
// Function in location_generator.h to print the coordinates of a Location structure
void print_loc(struct Location, int);

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
    // locs[0] = update_loc(locs[0]);
    // print_loc(locs[0], 0);
    for(int i = 0; i < 10; i++) {
      locs[i] = update_loc(locs[i]);
      print_loc(locs[i], i);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(PERIOD));
  }

  return 0;
}
