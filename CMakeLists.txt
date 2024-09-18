# CMakeList.txt: CMake project for Particle Fire Sim

cmake_minimum_required (VERSION 3.8)

# Enable Dinamic Reload for MSVC compilers, if there's support.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("ParticleFireSim")

set(SDL2_DIR "C:/SDL2-2.28.4/cmake")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(ParticleFireSim "main.cpp" "Enxame.cpp" "Particula.cpp" "Tela.cpp")
target_link_libraries(ParticleFireSim ${SDL2_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ParticleFireSim PROPERTY CXX_STANDARD 20)
endif()
