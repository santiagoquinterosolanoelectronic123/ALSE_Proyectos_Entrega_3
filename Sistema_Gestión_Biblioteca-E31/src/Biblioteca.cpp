#include "Biblioteca.h"
#include <iostream>

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
    std::cout << "Libro agregado: " << libro.getTitulo() << " (ISBN: " << libro.getISBN() << ")" << std::endl;
}

void Biblioteca::eliminarLibro(const std::string& isbn) {
    for (auto it = libros.begin(); it != libros.end(); ++it) {
        if (it->getISBN() == isbn) {
            libros.erase(it);
            std::cout << "Libro con ISBN " << isbn << " eliminado." << std::endl;
            return;
        }
    }
    std::cout << "Libro con ISBN " << isbn << " no encontrado." << std::endl;
}

std::vector<Libro> Biblioteca::buscarPorTitulo(const std::string& titulo) const {
    std::vector<Libro> resultados;
    for (const auto& libro : libros) {
        if (libro.getTitulo().find(titulo) != std::string::npos) {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

std::vector<Libro> Biblioteca::buscarPorAutor(const std::string& autor) const {
    std::vector<Libro> resultados;
    for (const auto& libro : libros) {
        if (libro.getAutor().find(autor) != std::string::npos) {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

std::vector<Libro> Biblioteca::buscarPorISBN(const std::string& isbn) const {
    std::vector<Libro> resultados;
    for (const auto& libro : libros) {
        if (libro.getISBN() == isbn) {
            resultados.push_back(libro);
        }
    }
    return resultados;
}

void Biblioteca::mostrarDisponibles() const {
    std::cout << "Libros disponibles:" << std::endl;
    for (const auto& libro : libros) {
        if (libro.isDisponible()) {
            std::cout << "- " << libro.getTitulo() << " por " << libro.getAutor() << " (ISBN: " << libro.getISBN() << ")" << std::endl;
        }
    }
}

bool Biblioteca::prestarLibro(const std::string& isbn) {
    for (auto& libro : libros) {
        if (libro.getISBN() == isbn && libro.isDisponible()) {
            libro.setDisponible(false);
            return true;
        }
    }
    return false;
}

bool Biblioteca::devolverLibro(const std::string& isbn) {
    for (auto& libro : libros) {
        if (libro.getISBN() == isbn && !libro.isDisponible()) {
            libro.setDisponible(true);
            return true;
        }
    }
    return false;
}
