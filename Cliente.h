#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    std::string rut;
    std::string discapacidad;
    std::string tipoDiscapacidad;

public:
    // Constructor
    Cliente(std::string rut, std::string discapacidad, std::string tipoDiscapacidad);

    // Getters
    std::string getRut() const;
    std::string tieneDiscapacidad() const;
    std::string getTipoDiscapacidad() const;

    // Setters
    void setRut(std::string rut);
    void setDiscapacidad(std::string discapacidad);
    void setTipoDiscapacidad(std::string tipoDiscapacidad);
};

#endif