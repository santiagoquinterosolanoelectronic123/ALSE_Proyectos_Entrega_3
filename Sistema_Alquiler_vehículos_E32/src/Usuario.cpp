#include "../include/Usuario.h"
#include "../include/SistemaAlquiler.h"
#include <iostream>

Usuario::Usuario(const std::string& id) : id(id) {}

bool Usuario::puedeAlquilar() const {
    return vehiculosAlquilados.size() < 3; // Limit of 3 rentals
}

void Usuario::alquilarVehiculo(SistemaAlquiler& sistema, const std::string& idVehiculo) {
    if (!puedeAlquilar()) {
        std::cout << id << " ha alcanzado el límite de alquileres (3).\n";
        return;
    }
    if (sistema.alquilarVehiculo(idVehiculo)) {
        vehiculosAlquilados.push_back(idVehiculo);
        std::cout << id << " alquiló el vehículo con ID " << idVehiculo << ".\n";
    } else {
        std::cout << "Vehículo con ID " << idVehiculo << " no disponible o no encontrado.\n";
    }
}

void Usuario::devolverVehiculo(SistemaAlquiler& sistema, const std::string& idVehiculo) {
    for (auto it = vehiculosAlquilados.begin(); it != vehiculosAlquilados.end(); ++it) {
        if (*it == idVehiculo) {
            if (sistema.devolverVehiculo(idVehiculo)) {
                vehiculosAlquilados.erase(it);
                std::cout << id << " devolvió el vehículo con ID " << idVehiculo << ".\n";
            } else {
                std::cout << "Error al devolver el vehículo con ID " << idVehiculo << ".\n";
            }
            return;
        }
    }
    std::cout << id << " no tiene alquilado el vehículo con ID " << idVehiculo << ".\n";
}

void Usuario::mostrarAlquilados(const SistemaAlquiler& sistema) const {
    std::cout << id << " tiene alquilados (" << vehiculosAlquilados.size() << "/3):\n";
    for (const auto& idVehiculo : vehiculosAlquilados) {
        auto resultados = sistema.buscarPorId(idVehiculo);
        if (!resultados.empty()) {
            resultados[0]->mostrarInformacion();
        }
    }
}

std::string Usuario::getId() const {
    return id;
}