program: clients.cpp
	g++ -std=c++17 clients.cpp position.pb.cc -o clients `pkg-config --cflags --libs protobuf`

proto: position.proto
	protoc -I=./ --cpp_out=./ ./position.proto

all: all
	g++ -std=c++17 clients.cpp position.pb.cc -o clients `pkg-config --cflags --libs protobuf`
	protoc -I=./ --cpp_out=./ ./position.proto
