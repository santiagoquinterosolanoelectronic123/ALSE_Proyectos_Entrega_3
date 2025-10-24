#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class SistemaAlquiler;

class Usuario {
protected:
    std::string id;
    std::vector<std::string> vehiculosAlquilados;

public:
    Usuario(const std::string& id);
    virtual ~Usuario() = default;
    bool puedeAlquilar() const;
    void alquilarVehiculo(SistemaAlquiler& sistema, const std::string& idVehiculo);
    void devolverVehiculo(SistemaAlquiler& sistema, const std::string& idVehiculo);
    void mostrarAlquilados(const SistemaAlquiler& sistema) const;
    std::string getId() const;
};

#endif // USUARIO_H