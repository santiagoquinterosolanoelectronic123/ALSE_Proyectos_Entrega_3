#include "../include/Usuario.h"
#include <iostream>

Usuario::Usuario(const std::string& nombre, const std::string& id, int limite)
    : nombre(nombre), id(id), limitePrestamos(limite) {}

bool Usuario::puedePrestar() const {
    return librosPrestados.size() < static_cast<size_t>(limitePrestamos);
}

void Usuario::prestarLibro(Biblioteca& biblioteca, const std::string& isbn) {
    if (!puedePrestar()) {
        std::cout << nombre << " ha alcanzado el límite de préstamos (" << limitePrestamos << ").\n";
        return;
    }
    auto resultados = biblioteca.buscarPorISBN(isbn);
    if (!resultados.empty() && biblioteca.prestarLibro(isbn)) {
        librosPrestados.push_back(isbn);
        std::cout << nombre << " prestó el libro con ISBN " << isbn << ".\n";
    } else {
        std::cout << "Libro con ISBN " << isbn << " no disponible o no encontrado.\n";
    }
}

void Usuario::devolverLibro(Biblioteca& biblioteca, const std::string& isbn) {
    for (auto it = librosPrestados.begin(); it != librosPrestados.end(); ++it) {
        if (*it == isbn) {
            if (biblioteca.devolverLibro(isbn)) {
                librosPrestados.erase(it);
                std::cout << nombre << " devolvió el libro con ISBN " << isbn << ".\n";
            } else {
                std::cout << "Error al devolver el libro con ISBN " << isbn << ".\n";
            }
            return;
        }
    }
    std::cout << nombre << " no tiene prestado el libro con ISBN " << isbn << ".\n";
}

void Usuario::mostrarPrestados(const Biblioteca& biblioteca) const {
    std::cout << nombre << " tiene prestados (" << librosPrestados.size() << "/" << limitePrestamos << "):\n";
    for (const auto& isbn : librosPrestados) {
        auto resultados = biblioteca.buscarPorISBN(isbn);
        if (!resultados.empty()) {
            std::cout << "- " << resultados[0].getTitulo() << " por " << resultados[0].getAutor() << " (ISBN: " << isbn << ")\n";
        }
    }
}

std::string Usuario::getNombre() const {
    return nombre;
}
std::string Usuario::getId() const {
    return id;
}
