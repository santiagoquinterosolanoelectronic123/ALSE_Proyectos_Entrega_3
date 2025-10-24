#include "../include/Estudiante.h"

Estudiante::Estudiante(const std::string& nombre, const std::string& id)
    : Usuario(nombre, id, 3) {} // Límite de 3 préstamos
    