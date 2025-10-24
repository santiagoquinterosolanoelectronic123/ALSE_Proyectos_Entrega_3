#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string id;
    std::string marca;
    bool disponible;

public:
    Vehiculo(const std::string& id, const std::string& marca, bool disponible = true);
    virtual ~Vehiculo() = default;
    virtual void mostrarInformacion() const = 0; // Pure virtual to include type
    std::string getId() const;
    bool isDisponible() const;
    void setDisponible(bool disp);
};

#endif // VEHICULO_H
