//============================================================================
// Name        : esercizio4-ASD.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "servizi.h"

using namespace std;

int main() {

	Mappa mappa = acquisisciMappa();
	Lista<elem,NodoLista<elem>*> lista;
	string citta;
	NodoGrafo *c;

	do {
		cout << "Scegliere citta per la quale si vogliono ";
		cout << "visualizzare i collegamenti (BA/TA/BR) ";
		cout << endl << endl << "Scelta: ";
		cin >> citta;
		system("CLS");
	} while(!cittaPresente(citta,mappa));

	c = ricercaCitta(citta, mappa);
	lista = cittaCollegate(c, mappa);
	stampaLista(lista);

	return 0;
}
