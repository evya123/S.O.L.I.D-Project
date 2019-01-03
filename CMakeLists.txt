cmake_minimum_required(VERSION 3.13)
project(S.O.L.I.D)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

add_executable(Dev main.cpp server_side/MySerialServer.h server_side/MySerialServer.cpp server_side/Server.h server_side/ClientHandler.h server_side/MyTestClientHandler.cpp server_side/MyTestClientHandler.h server_side/Solver.h server_side/CacheManager.h server_side/FileCacheManager.cpp server_side/FileCacheManager.h server_side/StringReverser.cpp server_side/StringReverser.h)