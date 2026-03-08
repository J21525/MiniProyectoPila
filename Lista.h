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
		delete[] arreglo;
	}
	int END() {
		return tamano + 1;
	}
	void Insertar(int p, int x) {
		if (p > END() || p <= 0) {
			cout << "No se puede Insertar en la Lista" << endl;
			return;
		}
		if (p == END() || (1 >= p &&  p <= tamano)){
			int* arreglo2 = new int[tamano + 1];
			for (int i = 0; i < tamano+1; i++) {
				if (1 >= p && p <= tamano) {
					if (i < p - 1)
						arreglo2[i] = arreglo[i];
					else if (i == p - 1)
						arreglo2[i] = x;
					else
						arreglo2[i] = arreglo[i - 1];
				}
				else
					arreglo2[i] = arreglo[i];
			}
			if (!(1 >= p && p <= tamano))
				arreglo2[p - 1] = x;
			delete[] arreglo;
			arreglo = arreglo2;
			tamano += 1;
			return;
		}
		arreglo[p - 1] = x;
		return;

	}
	int Localizar(int x) {
		for (int i = 0; i < tamano; i++) {
			if (arreglo[i] == x) {
				return i + 1;
			}
		}
		return END();
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
		arreglo = arreglo2;
		tamano -= 1;
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
		for (int i = 0; i < tamano; i++) {
			cout << arreglo[i] << "  ";
		}
		cout << endl;
	}
	void ImprimirElemento(int p) {
		cout << arreglo[p-1] << " "; 
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
