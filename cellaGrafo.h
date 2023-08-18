/*
 * cellaGrafo.h
 *
 *  Created on: 31/gen/2015
 *      Author: rocco
 */

#ifndef CELLAGRAFO_H_
#define CELLAGRAFO_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef bool boolean;

template <class T>
class cellaGrafo {
public:
	T getInfo();
	void setInfo(T);
	boolean getVisitato();
	void setVisitato(boolean);
	cellaGrafo();
private:
	T infoNodo;
	boolean visitato; //utile per DFS/BFS
};

template <class T>
T cellaGrafo<T>::getInfo() {
	return infoNodo;
}

template <class T>
void cellaGrafo<T>::setInfo(T info) {
	infoNodo = info;
}

template <class T>
boolean cellaGrafo<T>::getVisitato() {
	return visitato;
}

template <class T>
void cellaGrafo<T>::setVisitato(boolean val) {
	visitato = val;
}

template <class T>
cellaGrafo<T>::cellaGrafo() {
	visitato = false;
}

#endif /* CELLAGRAFO_H_ */
