#ifndef SISTEMA_ALQUILER_H
#define SISTEMA_ALQUILER_H

#include "vehiculo.h"
#include <vector>

class SistemaAlquiler {
private:
    std::vector<Vehiculo*> vehiculos;

public:
    ~SistemaAlquiler();
    void agregarVehiculo(Vehiculo* vehiculo);
    void mostrarDisponibles() const;
    void mostrarAlquilados() const; // Added to show rented vehicles
    std::vector<Vehiculo*> buscarPorId(const std::string& id) const;
    bool alquilarVehiculo(const std::string& id);
    bool devolverVehiculo(const std::string& id);
};

#endif // SISTEMA_ALQUILER_H