#include <iostream>
#include <zmq.hpp>
#include "position.pb.h"

static zmq::context_t ctx;

int main(void) {
  zmq::socket_t sock(ctx, zmq::socket_type::pull);
  sock.connect("tcp://127.0.0.1:5555");
  std::cout << "Connecting socket to tcp://127.0.0.1:5555" << std::endl;

  while(1) {
    zmq::message_t z_in;
    sock.recv(z_in);

    position::GeneratedPosition gen_pos;
    gen_pos.ParseFromArray(z_in.data(), z_in.size());

    std::cout << "\n"
      << "Sensor " << gen_pos.sensorid() << ":"
      << "\nTimestamp: " << gen_pos.timestamp_usec()
      << "\nX-Value: " << gen_pos.mutable_position()->x()
      << " | Y-Value: " << gen_pos.mutable_position()->y()
      << " | Z-Value: " << gen_pos.mutable_position()->z() << std::endl;
  }
}
