#include "Usuario.h"
#ifndef PROFESOR_H
#define PROFESOR_H
 


class Profesor : public Usuario {
public:
    Profesor(const std::string& nombre, const std::string& id);
};

#endif // PROFESOR_H