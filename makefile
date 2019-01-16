all:
	g++ -std=c++14 main.cpp ThreadPool.h Algorithms/*.h Algorithms/*.cpp Input/*.h Input/*.cpp 		server_side/*.h server_side/*.cpp -Wall -pthread -w
