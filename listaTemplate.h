/*
 * listaTemplate.h
 *
 *  Created on: 18/dic/2014
 *      Author: rocco
 */

#ifndef LISTATEMPLATE_H_
#define LISTATEMPLATE_H_

#include <iostream>
#include "assert.h"
#include "nodoListaTemplate.h"

using namespace std;

typedef bool boolean;
//typedef NodoLista<int>* posizione; NEL MAIN

template <class tipoelem,class posizione>
class Lista {
public:
	void creaLista();
	boolean listaVuota();
	tipoelem leggiLista(posizione);
	void scriviLista(tipoelem,posizione);
	posizione primoLista();
	boolean fineLista(posizione);
	posizione succLista(posizione);
	posizione precLista(posizione);
	void insLista(tipoelem,posizione);
	void cancLista(posizione);
	 Lista();
	~Lista();
private:
	NodoLista<tipoelem> *testa;
};

template <class T,class posizione>
void Lista<T,posizione>::creaLista() {
	testa = NULL;
}

template <class T,class posizione>
boolean Lista<T,posizione>::listaVuota() {
	return (testa == NULL);
}

template <class T,class posizione>
T Lista<T,posizione>::leggiLista(posizione pos) {
	assert(!listaVuota());
	return pos->dato;
}

template <class T,class posizione>
void Lista<T,posizione>::scriviLista(T elem,posizione pos) {
	assert(!listaVuota() && pos!=NULL);
	pos->dato = elem;
}

template <class T,class posizione>
posizione Lista<T,posizione>::primoLista() {
	return testa;
}

template <class T,class posizione>
boolean Lista<T,posizione>::fineLista(posizione pos) {
	return (pos == NULL);
}

template <class T,class posizione>
posizione Lista<T,posizione>::succLista(posizione pos) {
	assert(pos != NULL);
	return pos->succ;
}

template <class T,class posizione>
posizione Lista<T,posizione>::precLista(posizione pos) {
	assert(pos != NULL);
	return pos->prec();
}

template <class T,class posizione>
void Lista<T,posizione>::insLista(T elem, posizione p) {
	NodoLista<T>* nuovo = new NodoLista<T>();
	nuovo->dato = elem;

	if (p != NULL) {
		nuovo->prec = p->prec;
		nuovo->succ = p;
		p->prec = nuovo;
		if (p == primoLista())
			testa = nuovo;
		else
			p->prec->prec->succ = nuovo;
	} else {
		if (listaVuota()) {
			nuovo->prec = NULL;
			testa = nuovo;
		} else { //ultimo della lista
			p = primoLista();
			while(p->succ != NULL && !fineLista(p))
				p = succLista(p);
			p->succ = nuovo;
			nuovo->prec = p;
		}
		nuovo->succ = NULL;
	}
}

template <class T,class posizione>
void Lista<T,posizione>::cancLista(posizione p) {

	if (p != NULL) {
		if (listaVuota())
			cout << "Errore insLista(): La lista e Vuota" <<endl;
		else if ((p->prec == NULL) && (p->succ) == NULL)
			testa = NULL;
		else if (p == testa) {
			testa = p->succ;
			testa->prec = 0;
		} else if (p->succ == NULL) //cancellazione in coda
			p->prec->succ = NULL;
		else { //cancellazione in posizione generica
		 	p->succ->prec = p->prec;
		    p->prec->succ = p->succ;
		}
	} else cout << "Posizione non corretta" << endl;
}

template <class T,class posizione>
Lista<T,posizione>::Lista() {
	creaLista();
}

template <class T,class posizione>
Lista<T,posizione>:: ~Lista() {}

#endif /* LISTATEMPLATE_H_ */
