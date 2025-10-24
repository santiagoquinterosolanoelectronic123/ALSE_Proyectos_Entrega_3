#include "vehiculo.h"
#ifndef AUTO_H
#define AUTO_H

class Auto : public Vehiculo {
private:
    int capacidadPasajeros;

public:
    Auto(const std::string& id, const std::string& marca, int capacidadPasajeros, bool disponible = true);
    void mostrarInformacion() const override;
};

#endif // AUTO_H