// main.cpp: Martin Pfatrisch
// Description: The program sends sensor locations generated by the location generator

#include <iostream>
#include <time.h>
#include <zmq.hpp>

#include "location_generator.h"
#include "position.pb.h"


// Function in location_generator.h to generate a random location
struct Location init_loc(void);
// Funtion in location_generator.h to update the location with random coordinates
struct Location update_loc(struct Location);
// // Function in location_generator.h to print the coordinates of a Location structure
// void print_loc(struct Location, int);

// Function to set a GeneratedPosition
position::GeneratedPosition update_position(position::GeneratedPosition gen_pos, uint64_t sensor_id, struct Location loc);

static zmq::context_t ctx;

int main(void) {
  zmq::socket_t sock(ctx, zmq::socket_type::req);
  sock.connect("tcp://127.0.01:5555");




  const int period = 1000;

  // Array of locations
  struct Location locs[10];

  position::GeneratedPosition gen_pos;

  // Initialize locations
  for(int i = 0; i < 10; i++) {
    locs[i] = init_loc();

    // Initialize a new position
    gen_pos = update_position(gen_pos, i, locs[i]);
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(period));


  while(1) {
    for(int i = 0; i < 10; i++) {
      std::string msg_out = std::to_string(i);
      zmq::message_t z_out(msg_out);
      sock.send(z_out, zmq::send_flags::none);

      zmq::message_t z_in;
      sock.recv(z_in);
      std::cout
        << "\nSending: " << msg_out
        << " Received: " << z_in.to_string();

      // locs[i] = update_loc(locs[i]);
      //
      // // Update the position
      // gen_pos = update_position(gen_pos, i, locs[i]);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(period));
  }

  return 0;
}


/**
 * update_position: Updates a GeneratedPosition with a sensor id, a time stamp and values from a location
 * @param  [position::GeneratedPosition]          gen_pos   GeneratedPosition, that should be updated
 * @param  [uint64_t]                             sensor_id Identifiert of the sensor
 * @param  [uint64_t]                             t_stamp   Time stamp in seconds
 * @param  [struct Location]                      loc       Location, which should its x, y and z coordinates to the GeneratedPosition
 * @return [position::GeneratedPosition]                    The updated GeneratedPosition
 */
position::GeneratedPosition update_position(position::GeneratedPosition gen_pos, uint64_t sensor_id, struct Location loc) {
  uint64_t t_stamp;
  t_stamp = time(NULL);

  std::cout
    << "\nSensor " << sensor_id
    << "\nTimeStamp: " << t_stamp
    << "\nx = " << loc.x << " | "
    << "y = " << loc.y << " | "
    << "z = " << loc.z << std::endl;

  gen_pos.set_sensorid(sensor_id);
  gen_pos.set_timestamp_usec(t_stamp);
  gen_pos.mutable_position()->set_x(loc.x);
  gen_pos.mutable_position()->set_y(loc.y);
  gen_pos.mutable_position()->set_z(loc.z);

  std::cout << "Sensor " << sensor_id << " initialized: " << gen_pos.IsInitialized() << std::endl;

  return gen_pos;
}
