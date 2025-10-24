#include "../include/Profesor.h"

Profesor::Profesor(const std::string& nombre, const std::string& id)
    : Usuario(nombre, id, 5) {} // Límite de 5 préstamos