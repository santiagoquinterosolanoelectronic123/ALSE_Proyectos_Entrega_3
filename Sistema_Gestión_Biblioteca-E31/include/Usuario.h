#include "Libro.h"
#include <string>
#include <vector>
#include "Biblioteca.h"
#ifndef USUARIO_H
#define USUARIO_H


class Usuario {
protected:
    std::string nombre;
    std::string id;
    std::vector<std::string> librosPrestados; // Lista de ISBNs de libros prestados
    int limitePrestamos;

public:
    Usuario(const std::string& nombre, const std::string& id, int limite);
    virtual ~Usuario() = default; // Destructor virtual para herencia
    bool puedePrestar() const;
    void prestarLibro(Biblioteca& biblioteca, const std::string& isbn);
    void devolverLibro(Biblioteca& biblioteca, const std::string& isbn);
    void mostrarPrestados(const Biblioteca& biblioteca) const;
    std::string getNombre() const;
    std::string getId() const;  
};

#endif // USUARIO_H