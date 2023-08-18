/*
 * nodoListaTemplate.h
 *
 *  Created on: 18/dic/2014
 *      Author: rocco
 */

#ifndef NODOLISTATEMPLATE_H_
#define NODOLISTATEMPLATE_H_

#include <iostream>

using namespace std;

template <class tipoelem>
class NodoLista {
public:
	tipoelem dato;
	NodoLista<tipoelem>* prec;
	NodoLista<tipoelem>* succ;
	NodoLista();
	~NodoLista();
};

template <class T>
NodoLista<T>::NodoLista() {
	prec = NULL;
	succ = NULL;
}

template <class T>
NodoLista<T>::~NodoLista(){}

#endif /* NODOLISTATEMPLATE_H_ */
