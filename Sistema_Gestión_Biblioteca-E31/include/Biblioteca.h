#include "Libro.h"
#include <vector>
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    void agregarLibro(const Libro& libro);
    void eliminarLibro(const std::string& isbn);
    std::vector<Libro> buscarPorTitulo(const std::string& titulo) const;
    std::vector<Libro> buscarPorAutor(const std::string& autor) const;
    std::vector<Libro> buscarPorISBN(const std::string& isbn) const;
    void mostrarDisponibles() const;
    bool prestarLibro(const std::string& isbn); // Nuevo: Marca libro como no disponible
    bool devolverLibro(const std::string& isbn); // Nuevo: Marca libro como disponible
};
#endif // BIBLIOTECA_H
