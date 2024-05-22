#include "Cliente.h"
#include <iostream>

// Constructor
Cliente::Cliente(std::string rut, std::string discapacidad, std::string tipoDiscapacidad) {
    this->rut = rut;
    this->discapacidad = discapacidad;
    this->tipoDiscapacidad = tipoDiscapacidad;
}

// Getters
std::string Cliente::getRut() const {
    return rut;
}

std::string Cliente::tieneDiscapacidad() const {
    return discapacidad;
}

std::string Cliente::getTipoDiscapacidad() const {
    return tipoDiscapacidad;
}

// Setters
void Cliente::setRut(std::string rut) {
    this->rut = rut;
}

void Cliente::setDiscapacidad(std::string discapacidad) {
    this->discapacidad = discapacidad;
}

void Cliente::setTipoDiscapacidad(std::string tipoDiscapacidad) {
    this->tipoDiscapacidad = tipoDiscapacidad;
}
