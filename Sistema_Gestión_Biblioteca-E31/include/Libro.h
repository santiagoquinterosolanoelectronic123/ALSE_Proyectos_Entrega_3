#include <string>
#include <iostream>
#ifndef LIBRO_H
#define LIBRO_H

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string isbn;
    bool disponible;

public:
    Libro(const std::string& titulo, const std::string& autor, const std::string& isbn, bool disponible = true);
    
    std::string getTitulo() const;
    std::string getAutor() const;
    std::string getISBN() const;
    bool isDisponible() const;
    void setDisponible(bool disp);
};

#endif // LIBRO_H