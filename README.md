# ParticleFireSim

## Description

This is my first C++ project, made for the [C++ for complete begginers](https://www.caveofprogramming.com/p/c-beginners) course by John Purcell.

A simple Particle Simulator visualizer using SDL2.

## Setup

### Dependencies

- CMake

  You'll also need a C++ compiler along with CMake, [this link.](https://www.msys2.org/), for msys2 will provide both, if you already have a compiler, just download CMake from their [website.](https://cmake.org/download/)

- SDL2

  Download the SDL2 Library for you OS [here.](https://github.com/libsdl-org/SDL/releases)
  You'll need the devel-VC version for windows, for the project I used version 2.28.4, but it should work on the latest avaiable at the time.

### Clone this repo

  >``` sh
  >git clone https://github.com/Icaro-Godoi/ParticleFireSim
  >```

### Configuration

  Change the "C:/SDL2-2.28.4/cmake" option in ```set(SDL2_DIR "C:/SDL2-2.28.4/cmake")``` on the CMakeLists.txt file to the directory you've saved your SDL2 lib, be sure to save it in a folder that doesn't need special permissions to be accessed.

## Build

  Navigate to the root of the folder, open the command prompt there and do the following commands:

  >``` sh
  >mkdir out
  >cd out
  >cmake ..
  >cmake --build .
  >```

  Now you can find your .exe file in the Debug folder, for it to run you'll have to get the *SDL2.dll* file from *SDL2/lib/x64/* copy it and paste in the same directory or your .exe
