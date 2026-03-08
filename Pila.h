#pragma once
#include "Lista.h"
class Pila {
private:
	Lista* lista;
public:
	Pila() {
		lista = new Lista(0); //Iniciamos la Lista en 0, y como es dinámica al agregar elementos se irán agregando conforme ingresemos datos.
	}
	~Pila() {
		delete lista;
	}
	void push(int elemento) {
		lista->Insertar(elemento, 1); //Hay que recordar que la lista que cree va de 1 hasta tamaño, y END es tamaño+1
		cout << "Elemento Insertado Correctamente" << endl;
	}
	void pop() {
		lista->Suprimir(1); //Suprimimos la última acción, es decir el elemento que acabamos de meter
		cout << "Se ha suprimido la última acción" << endl;
	}
	void top() {
		cout << "El último elemento de la pila es: "; //Solo imprimimos el primer elemento de la lista que corresponde al primer elemento de nuestra pila
		lista->ImprimirElemento(1); //Agregue un método en Lista para simplificar el proceso
		cout << endl;
	}
	bool estaVacia() {
		if (lista->END() == 1) { //Verifica si END() es 1, dado que como es tamaño+1, si esta vacío tamañó sería 0. Recordemos que la lista es dinámica.
			cout << "La Pila esta vacía" << endl; 
			return true;
		}
		else {
			cout << "La Pila posee elementos" << endl;
			return false;
		}
	}
	void ProcesarPila() { //Método adicional para demostrar el uso de la Pila
		cout << "Procesando cola...." << endl;
		lista->Imprime(); //Simplificando el ejemplo de la Pila uso el imprimir normal de la lista dado que se procesa del primero elemento de la lista
		// (último en entrar) hasta al final de la lista (primero en entrar).
	}

};