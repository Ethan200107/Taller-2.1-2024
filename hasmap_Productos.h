#pragma once
#include <string>
#include "Producto.h"

struct Nodo_SubCategoria {
    std::string nombreSubCategoria;
    Nodo_SubCategoria* siguiente;
    Producto* ListaProductos;
    Nodo_SubCategoria(const std::string subCategoria) : nombreSubCategoria(subCategoria), siguiente(nullptr), ListaProductos(nullptr){}
    void setListaProductos(Producto* producto);
    Producto* getListaProductos();
};
struct Nodo_Categoria {
    std::string nombreCategoria;
    Nodo_Categoria* siguiente;
    Nodo_SubCategoria* ListaSubCategoria;
    Nodo_Categoria(const std::string& categoria) : nombreCategoria(categoria), siguiente(nullptr), ListaSubCategoria(nullptr){}
};


class hasmap_Productos
{
private:
   
    Nodo_Categoria** tabla;
    int tamanoTabla;
    int cantidadElementos;

public:

    hasmap_Productos();
    ~hasmap_Productos();

    void redimensionarTabla();
    void ingresar_categoria(const std::string categoria, const std::string subCategoria, const std::string nombreMedicamento, int valorMedicamento);
    int funcionHash(const std::string& clave);
    int getCantidad() const;
    void mostrarCategorias() const;
    Nodo_Categoria* buscarCategoria(std::string& clave);
};

