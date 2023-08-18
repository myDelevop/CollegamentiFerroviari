/*
 * servizi.h
 *
 *  Created on: 14/gen/2015
 *      Author: Rocco
 */

#ifndef SERVIZI_H_
#define SERVIZI_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "listaTemplate.h"
#include "grafoListaArchi.h"
#include "Collegamenti.h"
#include "elem.h"

using namespace std;

/* Non sono utilizzati i template poich� in questo specifico esercizio
 * conosciamo gi� a priori i tipi di dato da utilizzare e non risulta
 * quindi necessario generalizzare.
*/
typedef GrafoListaArchi<string,Collegamenti> Mappa;
typedef cellaGrafo<string> NodoGrafo;
typedef arcoGrafoListaArchi<Collegamenti, string> arcoGrafo;

Mappa acquisisciMappa();
void inserisciNodi(Mappa &);
void inserisciArchi1(Mappa &);
void inserisciArchi2(Mappa &);

NodoGrafo* ricercaCitta(string citta, Mappa &);
arcoGrafo* ricercaArco(NodoGrafo*, NodoGrafo*, Mappa &);
boolean cittaPresente(string, Mappa &);
//FUNZIONI PROGETTO
Lista<elem,NodoLista<elem>*> cittaCollegate (NodoGrafo*, Mappa);
elem aggiornaElem(NodoGrafo*,NodoGrafo*, Mappa);
void stampaLista(Lista<elem,NodoLista<elem>*>);
void stampaElem(elem);

#endif /* SERVIZI_H_ */
