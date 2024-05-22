// Taller 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "hasmap_Productos.h"
#include <vector>
using namespace std;



hasmap_Productos lecturaProductos() {
    hasmap_Productos productos;
	ifstream archivo("Productos.txt");
	if (!archivo.is_open()) {
		cerr << "No se pudo abrir el archivo." << std::endl;
		return productos;
	}

	string linea;
	while (getline(archivo, linea)) {
		string token; // token para poder obtener el string

		istringstream iss(linea); // llamamos al istingstream para poder separarlo

		vector<string> DatosProductos; // donde vamos a guardar todos los datos del Cliente

		while (getline(iss, token, ',')) { // hacemos todas las separaciones y las guardamos

			DatosProductos.push_back(token);
		}

		string nombreCategoria = DatosProductos[0];
		string nombre_Sub_Categoria = DatosProductos[1];
		string nombreProducto = DatosProductos[2];
		int valor = stoi(DatosProductos[3]);
		productos.ingresar_categoria(nombreCategoria,nombre_Sub_Categoria
			,nombreProducto,valor);
	}
	archivo.close(); return productos;
}

int main()
{   
    hasmap_Productos hashmapProductos;
    hashmapProductos = lecturaProductos();
	hashmapProductos.mostrarCategorias();
    // hacer el hasmap

    //hacer lectura de los clientes
    // guardar los clientes en un queue

    // empezar el menu
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
