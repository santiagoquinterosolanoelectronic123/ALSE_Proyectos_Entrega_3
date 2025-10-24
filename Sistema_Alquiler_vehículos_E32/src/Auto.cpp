#include "../include/Auto.h"
#include <iostream>

Auto::Auto(const std::string& id, const std::string& marca, int capacidadPasajeros, bool disponible)
    : Vehiculo(id, marca, disponible), capacidadPasajeros(capacidadPasajeros) {}

void Auto::mostrarInformacion() const {
    std::cout << "Tipo: Auto, ID: " << id << ", Marca: " << marca 
              << ", Capacidad de pasajeros: " << capacidadPasajeros 
              << ", Estado: " << (disponible ? "Disponible" : "Alquilado") << std::endl;
}