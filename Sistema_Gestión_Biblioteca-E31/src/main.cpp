#include "../include/Biblioteca.h"
#include "../include/Estudiante.h"
#include "../include/Profesor.h"
#include <iostream>
#include <limits>
#include <string>
#include <cctype>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu() {
    std::cout << "\n=== Sistema de Gestión de Biblioteca ===\n";
    std::cout << "1. Mostrar libros disponibles\n";
    std::cout << "2. Buscar libro por título\n";
    std::cout << "3. Buscar libro por autor\n";
    std::cout << "4. Prestar un libro\n";
    std::cout << "5. Devolver un libro\n";
    std::cout << "6. Mostrar préstamos de un usuario\n";
    std::cout << "7. Crear nuevo usuario (Estudiante o Profesor)\n";
    std::cout << "8. Agregar libros\n";
    std::cout << "9. Salir\n";
    std::cout << "=======================================\n";
    std::cout << "Seleccione una opción (1-9): ";
}

int getUserOption() {
    int option;
    while (true) {
        if (std::cin >> option && option >= 1 && option <= 9) {
            clearInputBuffer();
            return option;
        } else {
            std::cout << "Comando inválido, por favor solo se pueden números del 1 al 9: ";
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

std::string getValidUserType(const std::string& prompt) {
    std::string input;
    while (true) {
        input = getInputString(prompt);
        std::string lowerInput = input;
        for (char& c : lowerInput) {
            c = std::tolower(c);
        }
        if (lowerInput == "estudiante" || lowerInput == "profesor") {
            return input;
        }
        std::cout << "Tipo de usuario inválido. Use 'Estudiante' o 'Profesor'.\n";
    }
}

int main() {
    Biblioteca biblioteca;
    std::vector<Usuario*> usuarios;

    // Agregar libros de ejemplo
    biblioteca.agregarLibro(Libro("El Gran Gatsby", "F. Scott Fitzgerald", "978-3-16-148410-0"));
    biblioteca.agregarLibro(Libro("1984", "George Orwell", "978-0-452-28423-4"));
    std::cout << "\nLibros iniciales agregados.\n";

    while (true) {
        displayMenu();
        int opcion = getUserOption();

        if (opcion == 9) {
            std::cout << "\nSaliendo del sistema. ¡Gracias por usar la biblioteca!\n";
            break;
        }

        switch (opcion) {
            case 1: {
                std::cout << "\n--- Mostrar Libros Disponibles ---\n";
                biblioteca.mostrarDisponibles();
                std::cout << "---------------------------------\n";
                break;
            }
            case 2: {
                std::string titulo = getInputString("\nIngrese el título a buscar: ");
                std::cout << "\n--- Resultados de Búsqueda por Título ---\n";
                auto resultados = biblioteca.buscarPorTitulo(titulo);
                if (resultados.empty()) {
                    std::cout << "No se encontraron libros con el título \"" << titulo << "\".\n";
                } else {
                    for (const auto& libro : resultados) {
                        std::cout << "- " << libro.getTitulo() << " por " << libro.getAutor() 
                                  << " (ISBN: " << libro.getISBN() << ", " 
                                  << (libro.isDisponible() ? "Disponible" : "Prestado") << ")\n";
                    }
                }
                std::cout << "---------------------------------------\n";
                break;
            }
            case 3: {
                std::string autor = getInputString("\nIngrese el autor a buscar: ");
                std::cout << "\n--- Resultados de Búsqueda por Autor ---\n";
                auto resultados = biblioteca.buscarPorAutor(autor);
                if (resultados.empty()) {
                    std::cout << "No se encontraron libros del autor \"" << autor << "\".\n";
                } else {
                    for (const auto& libro : resultados) {
                        std::cout << "- " << libro.getTitulo() << " por " << libro.getAutor() 
                                  << " (ISBN: " << libro.getISBN() << ", " 
                                  << (libro.isDisponible() ? "Disponible" : "Prestado") << ")\n";
                    }
                }
                std::cout << "--------------------------------------\n";
                break;
            }
            case 4: {
                std::string id = getInputString("\nIngrese el ID del usuario: ");
                std::string isbn = getInputString("Ingrese el ISBN del libro a prestar: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == id) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << id << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Prestando Libro ---\n";
                    usuario->prestarLibro(biblioteca, isbn);
                    std::cout << "----------------------\n";
                }
                break;
            }
            case 5: {
                std::string id = getInputString("\nIngrese el ID del usuario: ");
                std::string isbn = getInputString("Ingrese el ISBN del libro a devolver: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == id) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << id << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Devolviendo Libro ---\n";
                    usuario->devolverLibro(biblioteca, isbn);
                    std::cout << "-------------------------\n";
                }
                break;
            }
            case 6: {
                std::string id = getInputString("\nIngrese el ID del usuario: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == id) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << id << "\" no encontrado.\n";
                } else {
                    std::cout << "\n--- Préstamos del Usuario ---\n";
                    usuario->mostrarPrestados(biblioteca);
                    std::cout << "-----------------------------\n";
                }
                break;
            }
            case 7: {
                std::string tipo = getValidUserType("\nIngrese el tipo de usuario (Estudiante/Profesor): ");
                std::string nombre = getInputString("Ingrese el nombre del usuario: ");
                std::string id = getInputString("Ingrese el ID del usuario: ");
                if (tipo == "Estudiante" || tipo == "estudiante") {
                    usuarios.push_back(new Estudiante(nombre, id));
                    std::cout << "\nEstudiante \"" << nombre << "\" creado con éxito.\n";
                } else if (tipo == "Profesor" || tipo == "profesor") {
                    usuarios.push_back(new Profesor(nombre, id));
                    std::cout << "\nProfesor \"" << nombre << "\" creado con éxito.\n";
                }
                break;
            }
            case 9: {
                std::string id = getInputString("\nIngrese el ID del usuario: ");
                Usuario* usuario = nullptr;
                for (auto u : usuarios) {
                    if (u->getId() == id) {
                        usuario = u;
                        break;
                    }
                }
                if (!usuario) {
                    std::cout << "\nUsuario con ID \"" << id << "\" no encontrado.\n";
                } else if (dynamic_cast<Profesor*>(usuario)) {
                    std::cout << "\n--- Agregar Libro (Profesor) ---\n";
                    std::string titulo = getInputString("Ingrese el título del libro: ");
                    std::string autor = getInputString("Ingrese el autor del libro: ");
                    std::string isbn = getInputString("Ingrese el ISBN del libro: ");
                    biblioteca.agregarLibro(Libro(titulo, autor, isbn));
                    std::cout << "Libro \"" << titulo << "\" agregado con éxito por el profesor " << id << ".\n";
                    std::cout << "-------------------------------\n";
                } else {
                    std::cout << "\nSolo los profesores pueden agregar libros.\n";
                }
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