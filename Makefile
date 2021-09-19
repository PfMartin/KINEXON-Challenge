clients: clients.cpp
	g++ -std=c++17 clients.cpp position.pb.cc -lzmq -lczmq -o clients `pkg-config --cflags --libs protobuf`

server: server.cpp
	g++ -std=c++17 server.cpp -lzmq -lczmq -o server

proto: position.proto
	protoc -I=./ --cpp_out=./ ./position.proto

all: all
	g++ -std=c++17 clients.cpp position.pb.cc -lzmq -lczmq -o clients `pkg-config --cflags --libs protobuf`
	g++ -std=c++17 server.cpp -lzmq -lczmq -o server
	protoc -I=./ --cpp_out=./ ./position.proto
