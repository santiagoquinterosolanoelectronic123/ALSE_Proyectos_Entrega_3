#include "../include/SistemaAlquiler.h"
#include "../include/Auto.h"
#include "../include/Bicicleta.h"
#include "../include/Usuario.h"
#include <iostream>
#include <limits>
#include <string>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "\n=== Sistema de Alquiler de Vehículos ===\n";
    std::cout << "1. Mostrar vehículos disponibles\n";
    std::cout << "2. Mostrar vehículos alquilados\n";
    std::cout << "3. Alquilar un vehículo\n";
    std::cout << "4. Devolver un vehículo\n";
    std::cout << "5. Mostrar vehículos alquilados por un usuario\n";
    std::cout << "6. Crear nuevo usuario\n";
    std::cout << "7. Salir\n";
    std::cout << "=======================================\n";
    std::cout << "Seleccione una opción (1-7): ";
}

int getUserOption() {
    int option;
    while (true) {
        if (std::cin >> option && option >= 1 && option <= 7) {
            clearInputBuffer();
            return option;
        } else {
            std::cout << "Comando inválido, por favor solo se pueden números del 1 al 7: ";
            clearInputBuffer();
        }
    }
}

std::string getInputString(const std::string& prompt) {
    std::string input;
    bool isValid = false;
    while (!isValid) {
        std::cout << prompt;
        std::getline(std::cin, input);
        bool isEmpty = true;
        for (char c : input) {
            if (!std::isspace(c)) {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty) {
            std::cout << "El campo no puede estar vacío.\n";
        } else {
            isValid = true;
        }
    }
    return input;
}

int main() {
    SistemaAlquiler sistema;
    std::vector<Usuario*> usuarios;

    // Agregar vehículos de ejemplo
    sistema.agregarVehiculo(new Auto("A001", "Toyota", 5));
    sistema.agregarVehiculo(new Bicicleta("B001", "Trek", "Montaña"));
    std::cout << "\nVehículos iniciales agregados.\n";

    while (true) {
        displayMenu();
        int opcion = getUserOption();

        if (opcion == 7) {
            std::cout << "\nSaliendo del sistema. ¡Gracias por usar el sistema de alquiler!\n";
            break;
        }

        switch (opcion) {
            case 1: {
                std::cout << "\n--- Mostrar Vehículos Disponibles ---\n";
                sistema.mostrarDisponibles();
                std::cout << "------------------------------------\n";
                break;
            }
            case 2: {
                std::cout << "\n--- Mostrar Vehículos Alquilados ---\n";
                sistema.mostrarAlquilados();
                std::cout << "------------------------------------\n";
                break;
            }
            case 3: {
                std::string idUsuario = getInputString("\nIngrese el ID del usuario: ");
                std::string idVehiculo = getInputString("Ingrese el ID del vehículo a alquilar: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == idUsuario) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << idUsuario << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Alquilando Vehículo ---\n";
                    usuario->alquilarVehiculo(sistema, idVehiculo);
                    std::cout << "--------------------------\n";
                }
                break;
            }
            case 4: {
                std::string idUsuario = getInputString("\nIngrese el ID del usuario: ");
                std::string idVehiculo = getInputString("Ingrese el ID del vehículo a devolver: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == idUsuario) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << idUsuario << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Devolviendo Vehículo ---\n";
                    usuario->devolverVehiculo(sistema, idVehiculo);
                    std::cout << "---------------------------\n";
                }
                break;
            }
            case 5: {
                std::string idUsuario = getInputString("\nIngrese el ID del usuario: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == idUsuario) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << idUsuario << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Vehículos Alquilados por el Usuario ---\n";
                    usuario->mostrarAlquilados(sistema);
                    std::cout << "------------------------------------------\n";
                }
                break;
            }
            case 6: {
                std::string id = getInputString("\nIngrese el ID del usuario: ");
                usuarios.push_back(new Usuario(id));
                std::cout << "\nUsuario \"" << id << "\" creado con éxito.\n";
                break;
            }
        }
    }

    // Liberar memoria de los usuarios
    for (auto usuario : usuarios) {
        delete usuario;
    }

    return 0;
}