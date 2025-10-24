# include <string>
#include <iostream>
#include "../include/Libro.h"

    
Libro::Libro(const std::string& titulo, const std::string& autor, const std::string& isbn, bool disponible)
    : titulo(titulo), autor(autor), isbn(isbn), disponible(disponible) {}

std::string Libro::getTitulo() const {
    return titulo;
}

std::string Libro::getAutor() const {
    return autor;
}

std::string Libro::getISBN() const {
    return isbn;
}

bool Libro::isDisponible() const {
    return disponible;
}

void Libro::setDisponible(bool disp) {
    disponible = disp;
}