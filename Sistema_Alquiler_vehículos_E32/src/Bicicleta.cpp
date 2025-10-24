#include "../include/Bicicleta.h"
#include <iostream>

Bicicleta::Bicicleta(const std::string& id, const std::string& marca, const std::string& tipo, bool disponible)
    : Vehiculo(id, marca, disponible), tipo(tipo) {}

void Bicicleta::mostrarInformacion() const {
    std::cout << "Tipo: Bicicleta, ID: " << id << ", Marca: " << marca 
              << ", Tipo de bicicleta: " << tipo 
              << ", Estado: " << (disponible ? "Disponible" : "Alquilado") << std::endl;
}