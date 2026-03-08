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
		lista->Insertar(1, elemento); //Hay que recordar que la lista que cree va de 1 hasta tamaño, y END es tamaño+1
		//Debemos tomar en cuenta que debemos modificar un tanto la lista, ya que como el diseño anterior reemplazaba el dato si ingresaba uno nuevo
		//Por lo que ahora deberé de moverlo también si ya existía, es decir hacer que entre en mi segunda condición de Insertar y modificarla.
		cout << "Elemento Insertado Correctamente" << endl;
	}
	void pop() {
		lista->Suprimir(1); //Suprimimos la última acción, es decir el elemento que acabamos de meter
		cout << "Se ha suprimido la última acción" << endl;
	}
	void top() {
		cout << "El último elemento de la pila es: "; //Solo imprimimos el primer elemento de la lista que corresponde al primer elemento de nuestra pila
		cout << lista->Recupera(lista->Primero()) << endl; //En caso de estar vacía Primero será END() y el dato -1, en cualquier otro caso 
		//el primer elemento será impreso. Bien puedo ser usado lista->Recupera(1).
	}
	void estaVacia() {
		if (lista->END() == 1) { //Verifica si END() es 1, dado que como es tamaño+1, si esta vacío tamañó sería 0. Recordemos que la lista es dinámica.
			cout << "La Pila esta vacía" << endl; 
		}
		else {
			cout << "La Pila posee elementos" << endl;
		}
	}
	void ProcesarPila() { //Método adicional para demostrar el uso de la Pila
		cout << "Procesando cola...." << endl;
		lista->Imprime(); //Simplificando el ejemplo de la Pila uso el imprimir normal de la lista dado que se procesa del primero elemento de la lista
		// (último en entrar) hasta al final de la lista (primero en entrar).
	}
	void Anula() {
		cout << "Vaciando Pila..." << endl;
		lista = new Lista(0); //O bien pudieramos utilizar lista->Anula();
	}
};