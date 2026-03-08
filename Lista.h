#pragma once
#include <iostream>
using namespace std;
class Lista {
private:
	int tamano;
	int* arreglo;
public:
	Lista(int longitud) { //Crea una lista dinámica conforme a la longitud solicitada.
		tamano = longitud;
		arreglo = new int[tamano];
		for (int i = 0; i < tamano; i++) {
			arreglo[i] = 1; //En este caso inserta 1 en cada elemento del arreglo recién creado.
		}
	}
	~Lista() {
		delete[] arreglo; //Elimina el puntero del arreglo creado.
	}
	int END() {
		return tamano + 1; //Determina END(), que en este caso es tamaño+1;
	}
	void Insertar(int p, int x) {
		if (p > END() || p <= 0) { //En caso de que se intente insertar en una posición no prevista, es decir mayor a END(), que es el espacio que esta
		//esperando a asignarse, no se realiza la operación
			cout << "No se puede Insertar en la Lista" << endl;
			return;
		}
		if (p == END() || (1 >= p &&  p <= tamano)){ //Decisión que expande el arreglo y asigna en una nueva posición.
			int* arreglo2 = new int[tamano + 1];
			for (int i = 0; i < tamano+1; i++) {
				if (1 >= p && p <= tamano) {
					if (i < p - 1) //Este arbol de decisiones determina si se intenta ingresar un elemento a un espacio p que existe entre 1 y tamaño
						arreglo2[i] = arreglo[i];// pues los datos anterior a él se queden donde están
					else if (i == p - 1)
						arreglo2[i] = x; //Agrega el elemento a la posición que se espera
					else
						arreglo2[i] = arreglo[i - 1]; //Y los que estpan luego de él se muevan a nueva posición después.
				}
				else
					arreglo2[i] = arreglo[i]; // De otra forma pues solo se copian. Podríamos considerar que el árbol anterior aplica a cualquier caso
					//dado que si p esta después de tamaño es decir, es END(), pues nunca pudiera salir de la primera condición.
			}
			if (!(1 >= p && p <= tamano))
				arreglo2[p - 1] = x;
			delete[] arreglo; //Limpia el arreglo principal
			arreglo = arreglo2; //Copia el arreglo2 en arreglo 2
			tamano += 1;
			return; //<--- Aquí arreglo2 deja de existir y solo queda el arreglo principal apuntando al espacio esperado.
		}
		//arreglo[p - 1] = x; //Este espacio ya no se cumple dado que si la posición no es END() o esta dentro o afuera del espacio del arreglo, pues no existe.
		//return;

	}
	int Localizar(int x) {
		for (int i = 0; i < tamano; i++) {
			if (arreglo[i] == x) {
				return i + 1;
			}
		}
		return END();
	}
	int Recupera(int p) { //Recupera devuelve el valor en la posición indicada, sino muestra un mensaje de error y devuelve -1.
		if (p <= 0 || p > tamano) {
			cout << "Resultado No Definido : ";
			return -1;
		}
		return arreglo[p - 1]; 
	}
	void Suprimir(int p) { //Suprimir realiza una tarea similar a Insertar, pero este método solo reduce el tamaño y desecha el que vamos a suprimir.
		if (p <= 0 || p > tamano) {
			cout << "Resultado No Definido.";
			return;
		}
		int contador = 0;
		int* arreglo2 = new int[tamano - 1]; //Determina e arreglo secundario con tamaño-1, menor al anterior
		for (int i = 0; i < tamano; i++) { //Recorre todo arreglo principal
			if (i != p - 1) {
				arreglo2[contador] = arreglo[i]; // Y solo copia las posiciones que no son el elemento indicado a suprimir
				contador++;
			}
		}
		delete[] arreglo; //Limpia el arreglo principal 
		arreglo = arreglo2; //Asigna al arreglo2 
		tamano -= 1; //Reduce tamaño
		//y Aqupi arreglo queda apuntando a lo que apuntaba arreglo2
	}
	int Siguiente(int p) { //Siguiente solo determina si existe el siguiente elemento, si no eixste puede ser END(), en otro caso retorna -1, si existe
	//retorna la siguiente posición.
		if (p == tamano)
			return END();
		else if (p <= 0 || p > tamano)
			return -1;
		else
			return p + 1;
	}
	int Anterior(int p) { //Misma lógica que Siguiente, aplica hacía atrás, si no existe solo puede retornar -1, pero podemos consultar a END()
		if (p == END())
			return tamano;
		else if (p > END() || p <= 1)
			return -1;
		else
			return p - 1;

	}
	void Anula() { //Asigna el arreglo a un arreglo de int vacío.
		tamano = 0;
		delete[] arreglo;
		arreglo = new int[0];
	}
	int Primero() { //Determina si existe o no, en caso de no existir el arreglo está vacío y devuelve END(), sino pues devuelve 1, posición.
		if (tamano == 0)
			return END();
		else
			return 1;
	}
	void Imprime() { //Imprime todo el arreglo de forma ordenada por posición, es decir, el primer elemento hasta último.
		for (int i = 0; i < tamano; i++) {
			cout << arreglo[i] << "  ";
		}
		cout << endl;
	}
	void Purge() { //Método que eliman datos duplicados, utiliza los métodos anteriores y recorre dos veces dado que tiene que comprar si ese dato esta
	//presente o no en el arreglo, el elemento que se analiza siempre se toma como el primero, dado que va eliminando las copias que encuentra.
		for (int i = 0; Siguiente(i) != END(); i++) {
			for (int j = i + 1; Siguiente(j) != END(); j++) {
				if (arreglo[i] == arreglo[j]) {
					Suprimir(j);
					j--;
				}
			}
		}
	}
};
