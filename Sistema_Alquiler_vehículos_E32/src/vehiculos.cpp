#include "../include/vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo(const std::string& id, const std::string& marca, bool disponible)
    : id(id), marca(marca), disponible(disponible) {}

std::string Vehiculo::getId() const {
    return id;
}

bool Vehiculo::isDisponible() const {
    return disponible;
}

void Vehiculo::setDisponible(bool disp) {
    disponible = disp;
}