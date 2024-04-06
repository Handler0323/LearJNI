
cmake_minimum_required(VERSION 3.6.0)


add_library(people-lib
        SHARED
        people/people.cpp)



add_library( # Sets the name of the library.
        myapplication

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        native-lib.cpp)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries(
        myapplication
        people-lib
        ${log-lib})