all: main.cpp
	g++ -o main main.cpp
	protoc -I=./ --cpp_out=./ ./generated_position.proto

program: main.cpp
	g++ -o main main.cpp

proto: generated_position.proto
	protoc -I=./ --cpp_out=./ ./generated_position.proto
