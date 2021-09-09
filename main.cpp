// main.cpp: Martin Pfatrisch
// Description: Runs the main program for the challenge

#include <iostream>
#include <time.h>

// struct Location: Defines a location with 3 coordinates
struct Location {
  int x;
  int y;
  int z;
};

struct Location generatePosition(void); // Function to get a random location

using namespace std;

/**
 * [main description]
 * @return [description]
 */
int main() {
  int interval = 1; // Frequency 1 Hz

  time_t start = time(0);

  while(1) {
    if(time(0)-start == interval) {
      generatePosition();
      start = start + interval;
    }
  }

  return 0;
}

/**
 * [generatePosition description]
 * @return [description]
 */
struct Location generatePosition() {
  struct Location l;
  l.x = 10;
  l.y = 10;
  l.z = 10;

  cout << "x = " << l.x << "\ny = " << l.y << "\nz = " << l.z << endl;

  return l;
}
