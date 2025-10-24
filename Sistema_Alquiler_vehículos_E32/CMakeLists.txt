cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Sistema_Alquiler_vehiculos)

include_directories(include)

add_library(Auto src/Auto.cpp)
add_library(Bicicleta src/Bicicleta.cpp)
add_library(S_Alquiler src/SistemaAlquiler.cpp)
add_library(vehiculos src/vehiculos.cpp)
add_library(usuario src/Usuario.cpp)

add_executable(alquiler src/main.cpp )
target_link_libraries(alquiler Auto Bicicleta S_Alquiler vehiculos usuario)