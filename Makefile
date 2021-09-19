clients: clients.cpp
	g++ -std=c++17 clients.cpp position.pb.cc -lzmq -lczmq -o clients `pkg-config --cflags --libs protobuf`

server: server.cpp
	g++ -std=c++17 server.cpp position.pb.cc -lzmq -lczmq -o server `pkg-config --cflags --libs protobuf`

proto: position.proto
	protoc -I=./ --cpp_out=./ ./position.proto

all: all
	g++ -std=c++17 clients.cpp position.pb.cc -lzmq -lczmq -o clients `pkg-config --cflags --libs protobuf`
	g++ -std=c++17 server.cpp position.pb.cc -lzmq -lczmq -o server `pkg-config --cflags --libs protobuf`
	protoc -I=./ --cpp_out=./ ./position.proto
