#include <iostream>
#include <zmq.hpp>
#include "../include/position.pb.h"

static zmq::context_t ctx;

int main(void) {
  zmq::socket_t sock(ctx, zmq::socket_type::pull);
  sock.connect("tcp://127.0.0.1:5555");
  std::cout << "Connecting socket to tcp://127.0.0.1:5555" << std::endl;

  while(1) {
    zmq::message_t zIn;
    sock.recv(zIn);

    position::GeneratedPosition gen_pos;
    gen_pos.ParseFromArray(zIn.data(), zIn.size());

    std::cout << "\n"
      << "Sensor " << gen_pos.sensorid() << ":"
      << "\nTimestamp: " << gen_pos.timestampusec()
      << "\nX-Value: " << gen_pos.mutable_position()->x()
      << " | Y-Value: " << gen_pos.mutable_position()->y()
      << " | Z-Value: " << gen_pos.mutable_position()->z() << std::endl;
  }
}
