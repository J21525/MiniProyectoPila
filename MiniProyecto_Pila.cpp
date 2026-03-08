#include "Pila.h"
#include <locale.h>
int main(){
    setlocale(LC_ALL, "spanish");
    cout << "EJEMPLO DE PILA" << endl;
    cout << "<----- CREANDO PILA..." << endl;
    Pila* prueba = new Pila();
    cout << "------> VERIFICANDO SI ESTA VACÍA..." << endl;
    prueba->estaVacia();
    cout << "<----- INSERTANDO DATOS..." << endl;
    cout << "   <---- Elemento 1: [10]..." << endl;
    prueba->push(10);
    cout << "   <---- Elemento 2: [11]..." << endl;
    prueba->push(11);
    cout << "   <---- Elemento 3: [9]..." << endl;
    prueba->push(9);
    cout << "   <---- Elemento 4: [8]..." << endl;
    prueba->push(8);
    cout << "------> VERIFICANDO SI ESTA VACÍA..." << endl;
    prueba->estaVacia();
    cout << "------> SOLICITANDO ÚLTIMO DATO...." << endl;
    prueba->top();
    cout << "------> SUPRIMIENDO ÚLTIMO DATO..." << endl;
    prueba->pop();
    cout << "------> SOLICITANDO ÚLTIMO DATO...." << endl;
    prueba->top();
    cout << "------> SOLICITANDO PILA (ORDEN DE LOS DATOS)..." << endl;
    prueba->ProcesarPila();
}