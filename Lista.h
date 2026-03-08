#pragma once
#include <iostream>
using namespace std;
class Lista {
private:
	int tamano;
	int* arreglo;
public:
	Lista(int longitud) {
		tamano = longitud;
		arreglo = new int[tamano];
		for (int i = 0; i < tamano; i++) {
			arreglo[i] = 1;
		}
	}
	~Lista() {
		delete arreglo;
	}
	int END() {
		return tamano + 1;
	}
	void Insertar(int p, int x) {
		if (p > END() || p <= 0) {
			cout << "No se puede Insertar en la Lista" << endl;
			return;
		}
		if (p == END()) {
			int* arreglo2 = new int[tamano + 1];
			for (int i = 0; i < tamano; i++) {
				arreglo2[i] = arreglo[i];
			}
			arreglo2[p - 1] = x;
			delete[] arreglo;
			arreglo = arreglo2;
			tamano += 1;
			cout << "Insertado Correctamente" << endl;
			return;
		}
		arreglo[p - 1] = x;
		cout << "Insertado Correctamente" << endl;
		return;

	}
	int Localizar(int x) {
		for (int i = 0; i < tamano; i++) {
			if (arreglo[i] == x) {
				return i + 1;
			}
		}
		return tamano;
	}
	int Recupera(int p) {
		if (p <= 0 || p > tamano) {
			cout << "Resultado No Definido : ";
			return -1;
		}
		return arreglo[p - 1];
	}
	void Suprimir(int p) {
		if (p <= 0 || p > tamano) {
			cout << "Resultado No Definido.";
			return;
		}
		int contador = 0;
		int* arreglo2 = new int[tamano - 1];
		for (int i = 0; i < tamano; i++) {
			if (i != p - 1) {
				arreglo2[contador] = arreglo[i];
				contador++;
			}
		}
		delete[] arreglo;
		tamano -= 1;
		arreglo = arreglo2;
	}
	int Siguiente(int p) {
		if (p == tamano)
			return END();
		else if (p <= 0 || p > tamano)
			return -1;
		else
			return p + 1;
	}
	int Anterior(int p) {
		if (p == END())
			return tamano;
		else if (p > END() || p <= 1)
			return -1;
		else
			return p - 1;

	}
	void Anula() {
		tamano = 0;
		delete[] arreglo;
		arreglo = new int[0];
	}
	int Primero() {
		if (tamano == 0)
			return END();
		else
			return 1;
	}
	void Imprime() {
		cout << "Lista:  ";
		for (int i = 0; i < tamano; i++) {
			cout << arreglo[i] << "  ";
		}
		cout << endl;
	}
	void Purge() {
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
