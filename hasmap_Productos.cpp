#include "hasmap_Productos.h"
#include <iostream>

hasmap_Productos::hasmap_Productos():
    tamanoTabla(10), cantidadElementos(0) {
    // Inicializar la tabla con el tamaño predeterminado
    
    tabla = new Nodo_Categoria * [tamanoTabla];
    
    for (int i = 0; i < tamanoTabla; ++i) {
        tabla[i] = nullptr;
    }
}

int hasmap_Productos::funcionHash(const std::string& clave) {
    int hash = 0;
    for (char c : clave) {
        hash += c;
    }
    return hash % tamanoTabla;
}


hasmap_Productos::~hasmap_Productos() {
}

void agregarproductos(Nodo_SubCategoria* subCategoria,const std::string nombreMedicamento, int valorMedicamento) {
    Producto* ListProductos = subCategoria->getListaProductos();
    Producto* nuevoProducto = new Producto(nombreMedicamento, valorMedicamento,1);
    if (ListProductos != nullptr) {
        while (ListProductos != nullptr) {

            if (ListProductos->getNombreProducto() == nombreMedicamento) {
                ListProductos->sumarProducto();
                break;
            }
            else if (ListProductos->getSiguiente() == nullptr) {
                ListProductos->setSiguiente(nuevoProducto);
                break;
            }
            ListProductos = ListProductos->getSiguiente();
        }
    }
else if (ListProductos == nullptr) {
        subCategoria->setListaProductos(nuevoProducto);
    }
    
};

void hasmap_Productos::ingresar_categoria(const std::string Categoria, 
    const std::string subcategoria,const std::string nombreMedicamento,int valorMedicamento)
{
    // creamos el nodo para subcategoria
    Nodo_SubCategoria* subcate = new Nodo_SubCategoria(subcategoria);

    int indice = funcionHash(Categoria);
    Nodo_Categoria* actual = tabla[indice];
    while (actual != nullptr) {
        if (actual->nombreCategoria == Categoria) {
            Nodo_SubCategoria* actualsub = actual->ListaSubCategoria;
            if (actualsub == nullptr) {
                actualsub = subcate;
            }
            else {
                while (actualsub != nullptr) {                        
                    if (actualsub->nombreSubCategoria == subcate->nombreSubCategoria) {
                        agregarproductos(actualsub,nombreMedicamento,valorMedicamento);
                        break;
        
                    }
                     else if (actualsub->siguiente == nullptr) {
                        agregarproductos(subcate, nombreMedicamento, valorMedicamento);
                        actualsub->siguiente = subcate;
                        break;
                    }
                    
                    actualsub = actualsub->siguiente;
                }
            }
            return;
        }
        actual = actual->siguiente;
    }

    // Si no hay nodos con la misma clave, agregar al principio de la lista
    Nodo_Categoria* nuevoNodo = new Nodo_Categoria(Categoria);
    nuevoNodo->siguiente = tabla[indice];
    tabla[indice] = nuevoNodo;
    nuevoNodo->ListaSubCategoria = subcate;
    agregarproductos(subcate, nombreMedicamento, valorMedicamento);
    //std::cout << subcate->nombreSubCategoria <<std::endl;
    cantidadElementos++;

    // Redimensionar la tabla si la carga excede el factor de carga
    if (cantidadElementos > tamanoTabla * 0.75) {
        redimensionarTabla();
    }
}

void hasmap_Productos::redimensionarTabla() {
    int nuevoTamano = tamanoTabla * 2; // se duplica el tamaño
    Nodo_Categoria** nuevaTabla = new Nodo_Categoria * [nuevoTamano];
    for (int i = 0; i < nuevoTamano; ++i) {
        nuevaTabla[i] = nullptr;
    }

    // Reasignar los nodos a la nueva tabla
    for (int i = 0; i < tamanoTabla; ++i) {
        Nodo_Categoria* actual = tabla[i];
        while (actual != nullptr) {
            Nodo_Categoria* siguiente = actual->siguiente;
            int nuevoIndice = funcionHash(actual->nombreCategoria) % nuevoTamano;
            actual->siguiente = nuevaTabla[nuevoIndice];
            nuevaTabla[nuevoIndice] = actual;
            actual = siguiente;
        }
    }

    // Liberar la memoria de la tabla antigua y actualizar el tamaño
    delete[] tabla;
    tabla = nuevaTabla;
    tamanoTabla = nuevoTamano;
}
int hasmap_Productos::getCantidad() const
{
    return cantidadElementos;
}

void hasmap_Productos::mostrarCategorias() const {
    std::cout << "Contenido de las Categorias :" << std::endl;
    std::cout << "----------------------" << std::endl;
    for (int i = 0; i < tamanoTabla; ++i) {
        Nodo_Categoria* actual = tabla[i];

        while (actual != nullptr) {
            std::cout << "- Categoria: " << actual->nombreCategoria << ":" << std::endl;
            Nodo_SubCategoria* subCate = actual->ListaSubCategoria;
            while (subCate != nullptr ) {
                std::cout << "   -   Subcategoria: " << subCate->nombreSubCategoria << std::endl;
                Producto* ListaP = subCate->ListaProductos;
                while (ListaP != nullptr) {
                    std::cout << "      -      Producto:  " << ListaP->getNombreProducto() << " Cantidad: " << ListaP->getCantidad() << std::endl;
                    ListaP = ListaP->getSiguiente();
                }
                subCate = subCate->siguiente;
            }
            actual = actual->siguiente;
        }
    }
}

Nodo_Categoria* hasmap_Productos::buscarCategoria(std::string& clave){
    int indice = funcionHash(clave);
    Nodo_Categoria* actual = tabla[indice];
    while (actual != nullptr) {
        if (actual->nombreCategoria == clave) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Nodo_SubCategoria::setListaProductos(Producto* producto)
{
    ListaProductos = producto;
}

Producto* Nodo_SubCategoria::getListaProductos()
{
    return ListaProductos;
}
