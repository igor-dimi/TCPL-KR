cmake_minimum_required(VERSION 3.15)
project(C_BrianKernighan C)

set(CMAKE_C_STANDARD 99)

add_executable(C_BrianKernighan main.c chapter1/HelloWorld.c chapter1/fahrenheit-to-celc.c chapter1/fahr-cels-programm.c)