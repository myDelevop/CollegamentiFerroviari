/*
 * arcoGrafoListaArchi.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef ARCOGRAFOLISTAARCHI_H_
#define ARCOGRAFOLISTAARCHI_H_

#include <iostream>
#include "cellaGrafo.h"

using namespace std;

template <class tipoArco,class tipoNodo>
class arcoGrafoListaArchi {
public:
	void setInfoArco(tipoArco);
	tipoArco getInfoArco();
	void setNodoPartenza(cellaGrafo<tipoNodo>*);
	cellaGrafo<tipoNodo>* getNodoPartenza();
	void setNodoArrivo(cellaGrafo<tipoNodo>*);
	cellaGrafo<tipoNodo>* getNodoArrivo();
private:
	cellaGrafo<tipoNodo>* nodoPartenza;
	cellaGrafo<tipoNodo>* nodoArrivo;
	tipoArco infoArco;
};

template <class T,class V>
void arcoGrafoListaArchi<T,V>::setInfoArco(T info) {
	infoArco = info;
}

template <class T,class V>
T arcoGrafoListaArchi<T,V>::getInfoArco() {
	return infoArco;
}

template <class T,class V>
void arcoGrafoListaArchi<T,V>::setNodoPartenza(cellaGrafo<V>* u) {
	nodoPartenza = u;
}

template <class T,class V>
cellaGrafo<V>* arcoGrafoListaArchi<T,V>::getNodoPartenza() {
	return nodoPartenza;
}

template <class T,class V>
void arcoGrafoListaArchi<T,V>::setNodoArrivo(cellaGrafo<V>* u) {
	nodoArrivo = u;
}

template <class T,class V>
cellaGrafo<V>* arcoGrafoListaArchi<T,V>::getNodoArrivo() {
	return nodoArrivo;
}

#endif /* ARCOGRAFOLISTAARCHI_H_ */
