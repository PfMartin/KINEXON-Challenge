clients: clients.cpp
	g++ -std=c++17 clients.cpp ../include/position.pb.cc -lzmq -lczmq -I"../include" -o ../build/clients `pkg-config --cflags --libs protobuf`

server: server.cpp
	g++ -std=c++17 server.cpp ../include/position.pb.cc -lzmq -lczmq -I"../include" -o ../build/server `pkg-config --cflags --libs protobuf`

proto: position.proto
	protoc -I=./ --cpp_out=./ ./position.proto

all: all
	g++ -std=c++17 clients.cpp ../include/position.pb.cc -lzmq -lczmq -I"../include" -o ../build/clients `pkg-config --cflags --libs protobuf`
	g++ -std=c++17 server.cpp ../include/position.pb.cc -lzmq -lczmq -I"../include" -o ../build/server `pkg-config --cflags --libs protobuf`
	protoc -I=./ --cpp_out=../include ./position.proto
