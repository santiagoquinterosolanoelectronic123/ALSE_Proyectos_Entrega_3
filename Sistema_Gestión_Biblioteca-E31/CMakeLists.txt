cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Sistema_Gestión_Biblioteca)

include_directories(include)

# Add the executable for CubeUnified.cpp
#add_executable(complex_exe clases.cpp)

add_library(Usuario src/Usuario.cpp)
add_library(Estudiante src/Estudiante.cpp)
add_library(Profesor src/Profesor.cpp)
add_library(Libro src/Libro.cpp)
add_library(Biblioteca src/Biblioteca.cpp)

# Add the executable for Complex with separated files
add_executable(Biblioteca_G src/main.cpp)
target_link_libraries(Biblioteca_G Usuario Estudiante Profesor Libro Biblioteca) 