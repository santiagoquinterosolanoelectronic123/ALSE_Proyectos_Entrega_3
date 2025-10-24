#include "Usuario.h"
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H



class Estudiante : public Usuario {
public:
    Estudiante(const std::string& nombre, const std::string& id);
};

#endif // ESTUDIANTE_H