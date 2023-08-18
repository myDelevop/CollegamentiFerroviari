/*
 * grafoListaArchi.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef GRAFOLISTAARCHI_H_
#define GRAFOLISTAARCHI_H_

#include <iostream>
#include "cellaGrafo.h"
#include "arcoGrafoListaArchi.h"
#include "listaTemplate.h"

template <class tipoNodo, class tipoArco>
class GrafoListaArchi {
public:
	typedef cellaGrafo<tipoNodo> nodoGrafo;
	typedef arcoGrafoListaArchi<tipoArco,tipoNodo> arcoGrafo;

	Lista<arcoGrafo*,NodoLista<arcoGrafo*>*> listaArchi;
	Lista<nodoGrafo*,NodoLista<nodoGrafo*>*> listaNodi;

	void creaGrafo();
	boolean grafoVuoto();
	void insNodo(nodoGrafo*, tipoNodo);
	void insArco(nodoGrafo*, nodoGrafo*, arcoGrafo*, tipoArco);
	void cancNodo(nodoGrafo*);
	void cancArco(nodoGrafo*,nodoGrafo*);
	Lista<cellaGrafo<tipoNodo>*,NodoLista<cellaGrafo<tipoNodo>*>*>
					adiacenti(nodoGrafo*);
	boolean esisteNodo(nodoGrafo*);
	boolean esisteArco(nodoGrafo*, nodoGrafo*);
	GrafoListaArchi();
};

template <class tipoNodo,class tipoArco>
void GrafoListaArchi<tipoNodo,tipoArco>::creaGrafo() {
	listaArchi.creaLista();
	listaNodi.creaLista();
}

template <class tipoNodo,class tipoArco>
boolean GrafoListaArchi<tipoNodo,tipoArco>::grafoVuoto() {
	boolean out;
	if (listaNodi.listaVuota())
		out = true;
	else
		out = false;
	return out;
}

template <class tipoNodo,class tipoArco>
void GrafoListaArchi<tipoNodo,tipoArco>::insNodo(nodoGrafo* u,
		tipoNodo dato) {
	NodoLista<nodoGrafo*>* pos;
	pos = listaNodi.primoLista();
	u->setInfo(dato);
	listaNodi.insLista(u,pos);
}

template <class tipoNodo,class tipoArco>
void GrafoListaArchi<tipoNodo,tipoArco>::insArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB, arcoGrafo* arco, tipoArco datoArco) {
	if (esisteNodo(nodoA) && esisteNodo(nodoB)) {
		arco->setInfoArco(datoArco);
		arco->setNodoPartenza(nodoA);
		arco->setNodoArrivo(nodoB);
		NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
		listaArchi.insLista(arco,pos);
	}
}

template <class tipoNodo,class tipoArco>
void GrafoListaArchi<tipoNodo,tipoArco>::cancNodo(nodoGrafo* nodoRead) {
	if (esisteNodo(nodoRead)) {
		boolean check = false;
		NodoLista<nodoGrafo*>* posNodo = listaNodi.primoLista();
		while (posNodo != NULL && check != true) {
			if (posNodo->dato == nodoRead) {
				listaNodi.cancLista(posNodo);
				check = true;
			} else
				posNodo = listaNodi.succLista(posNodo);
		}
		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;
		NodoLista<arcoGrafo*>* temp;
		pos = listaArchi.primoLista();
		while (pos != NULL) {
			arco = pos->dato;
			if (arco->getNodoArrivo() == nodoRead
					|| arco->getNodoPartenza() == nodoRead) {
				cout << "trovato arco x" << arco->getInfoArco() << endl;
				temp = listaArchi.succLista(pos);
				listaArchi.cancLista(pos);
				pos = listaArchi.primoLista();
			} else
				pos = listaArchi.succLista(pos);
		}
	}
}

template <class tipoNodo, class tipoArco>
void GrafoListaArchi<tipoNodo,tipoArco>::cancArco(nodoGrafo* nodoA,nodoGrafo* nodoB) {
	boolean check = false;
	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
	while (pos != NULL && check != true) {
		arco = pos->dato;
		if (arco->getNodoPartenza() == nodoA
				&& arco->getNodoArrivo() == nodoB) {
			check = true;
			listaArchi.cancLista(pos);
		} else
			pos = listaArchi.succLista(pos);
	}
}

template <class tipoNodo,class tipoArco>
Lista<cellaGrafo<tipoNodo>*,NodoLista<cellaGrafo<tipoNodo>*>*> GrafoListaArchi<tipoNodo,tipoArco>
	::adiacenti(nodoGrafo* nodo) {

	Lista<cellaGrafo<tipoNodo>*,NodoLista<cellaGrafo<tipoNodo>*>*> listaOut;
	listaOut.creaLista();
	if (esisteNodo(nodo)) {
		arcoGrafo* arco;
		NodoLista<arcoGrafo*>* pos;
		NodoLista<nodoGrafo*>* pos_ins;
		pos = listaArchi.primoLista();
		while (pos != NULL) {
			arco = pos->dato;
			if (arco->getNodoPartenza() == nodo) {
				pos_ins = listaOut.primoLista();
				listaOut.insLista(arco->getNodoArrivo(), pos_ins);
			}
			pos = listaArchi.succLista(pos);
		}
	}
	return listaOut;
}

template <class tipoNodo, class tipoArco>
boolean GrafoListaArchi<tipoNodo,tipoArco>::esisteNodo(nodoGrafo* nodo) {
	boolean check = false;
	NodoLista<nodoGrafo*>* pos = listaNodi.primoLista();
	while (pos != NULL && check != true) {
		if (pos->dato == nodo)
			check = true;
		else
			pos = listaNodi.succLista(pos);
	}
	return check;
}

template <class tipoNodo,class tipoArco>
boolean GrafoListaArchi<tipoNodo,tipoArco>::esisteArco(nodoGrafo* nodoA,
		nodoGrafo* nodoB) {
	boolean check = false;
	arcoGrafo* arco;
	NodoLista<arcoGrafo*>* pos = listaArchi.primoLista();
	while (pos != NULL && check != true) {
		arco = pos->dato;
		if (arco->getNodoPartenza() == nodoA
				&& arco->getNodoArrivo() == nodoB)
			check = true;
		else {
			check = false;
			pos = listaArchi.succLista(pos);
		}
	}
	return check;
}

template <class tipoNodo,class tipoArco>
GrafoListaArchi<tipoNodo,tipoArco>::GrafoListaArchi() {}

#endif /* GRAFOLISTAARCHI_H_ */
