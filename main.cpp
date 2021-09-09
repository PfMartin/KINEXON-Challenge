// main.cpp: Martin Pfatrisch
// Description: Runs the main program for the challenge

#include <iostream>
#include <time.h>

void generatePosition();

using namespace std;

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

void generatePosition() {
  cout << "Generated" << endl;
}
