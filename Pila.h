#pragma once
#include "Lista.h"
class Pila {
private:
	Lista Lista;
public:
	Pila();
	~Pila();
	void push(int elemento);
	void pop();
	int top();
	bool estaVacia();
};