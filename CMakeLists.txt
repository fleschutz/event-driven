cmake_minimum_required (VERSION 2.6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project (ivy)

add_executable (ivy
	hello_world.cpp
	EDP/Triggers.cpp
	EDP/Actions.cpp
	EDP/Time.cpp
	)
