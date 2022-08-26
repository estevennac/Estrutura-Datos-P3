#pragma once
#include <iostream>
#include <ctime>
#include <random>
template <class T>
class Nodo
{
private:
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo<T>(T, Nodo*);
	T get_dato();
	void set_dato(T);
	Nodo<T>* get_siguiente();
	void set_siguiente(Nodo*);

};
template<class T>
Nodo<T>::Nodo(T val, Nodo* sig)
{
	sig = NULL;
	this->dato = val;
	this->siguiente = sig;
}
template<class T>
T Nodo<T>::get_dato()
{
	return this->dato;
}

template<class T>
void Nodo<T>::set_dato(T val)
{
	this->dato = val;
}

template<class T>
Nodo<T>* Nodo<T>::get_siguiente()
{
	return this->siguiente;
}
template<class T>
void Nodo<T>::set_siguiente(Nodo<T>* nuevo)
{
	this->siguiente = nuevo;
}

