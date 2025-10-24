#ifndef BICICLETA_H
#define BICICLETA_H
#include "vehiculo.h"

class Bicicleta : public Vehiculo {
private:
    std::string tipo; // e.g., "Montaña", "Ciudad"

public:
    Bicicleta(const std::string& id, const std::string& marca, const std::string& tipo, bool disponible = true);
    void mostrarInformacion() const override;
};

#endif // BICICLETA_H