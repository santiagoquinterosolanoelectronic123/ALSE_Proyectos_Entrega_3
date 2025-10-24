#include "../include/SistemaAlquiler.h"
#include <iostream>

SistemaAlquiler::~SistemaAlquiler() {
    for (auto vehiculo : vehiculos) {
        delete vehiculo;
    }
}

void SistemaAlquiler::agregarVehiculo(Vehiculo* vehiculo) {
    vehiculos.push_back(vehiculo);
    std::cout << "Vehículo agregado: " << vehiculo->getId() << std::endl;
}

void SistemaAlquiler::mostrarDisponibles() const {
    std::cout << "Vehículos disponibles:" << std::endl;
    bool hasDisponibles = false;
    for (const auto& vehiculo : vehiculos) {
        if (vehiculo->isDisponible()) {
            vehiculo->mostrarInformacion();
            hasDisponibles = true;
        }
    }
    if (!hasDisponibles) {
        std::cout << "No hay vehículos disponibles." << std::endl;
    }
}

void SistemaAlquiler::mostrarAlquilados() const {
    std::cout << "Vehículos alquilados:" << std::endl;
    bool hasAlquilados = false;
    for (const auto& vehiculo : vehiculos) {
        if (!vehiculo->isDisponible()) {
            vehiculo->mostrarInformacion();
            hasAlquilados = true;
        }
    }
    if (!hasAlquilados) {
        std::cout << "No hay vehículos alquilados." << std::endl;
    }
}

std::vector<Vehiculo*> SistemaAlquiler::buscarPorId(const std::string& id) const {
    std::vector<Vehiculo*> resultados;
    for (const auto& vehiculo : vehiculos) {
        if (vehiculo->getId() == id) {
            resultados.push_back(vehiculo);
        }
    }
    return resultados;
}

bool SistemaAlquiler::alquilarVehiculo(const std::string& id) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getId() == id && vehiculo->isDisponible()) {
            vehiculo->setDisponible(false);
            return true;
        }
    }
    return false;
}

bool SistemaAlquiler::devolverVehiculo(const std::string& id) {
    for (auto& vehiculo : vehiculos) {
        if (vehiculo->getId() == id && !vehiculo->isDisponible()) {
            vehiculo->setDisponible(true);
            return true;
        }
    }
    return false;
}