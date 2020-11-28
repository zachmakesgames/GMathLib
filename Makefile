standard= -std=c++11

default: main.cpp vec.h mat.h
	g++ main.cpp $(standard)
