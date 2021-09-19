program: main.cpp
	g++ -std=c++17 main.cpp position.pb.cc -o main `pkg-config --cflags --libs protobuf`
	# g++ -o main main.cpp

proto: position.proto
	protoc -I=./ --cpp_out=./ ./position.proto

all: all
	g++ -lprotobuf -o main main.cpp
	protoc -I=./ --cpp_out=./ ./position.proto
