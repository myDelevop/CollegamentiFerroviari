/*
 * servizi.cpp
 *
 *  Created on: 14/gen/2015
 *      Author: Rocco
 */

#include "servizi.h"

Mappa acquisisciMappa() {
	Mappa G;
	int scelta;

	do {
		cout << "1. Acquisisci Grafo1" << endl << endl;
		cout << "2. Acquisisci Grafo2" << endl << endl;
		cout << "Scelta: ";
		cin >> scelta;
		system("CLS");
	} while( scelta != 1 && scelta != 2);

	inserisciNodi(G);
	if (scelta == 1)
		inserisciArchi1(G);
	else
		inserisciArchi2(G);



	return G;
}

void inserisciNodi(Mappa &G) {
	NodoGrafo *citta1 = new NodoGrafo();
	G.insNodo(citta1,"BR");
	NodoGrafo *citta2 = new NodoGrafo();
	G.insNodo(citta2,"BA");

	NodoGrafo *citta3= new NodoGrafo();
	G.insNodo(citta3,"TA");

}

void inserisciArchi1(Mappa &G) {
	NodoGrafo *citta1, *citta2;
	Collegamenti biglietto;

	citta1 = ricercaCitta("BA",G);
	citta2 = ricercaCitta("BR",G);
	arcoGrafo *arco1 = new arcoGrafo();
	biglietto.setEuro(8.87);
	biglietto.setMinuti(67);
	G.insArco(citta1,citta2,arco1,biglietto);

	citta1 = ricercaCitta("BR",G);
	citta2 = ricercaCitta("BA",G);
	arcoGrafo *arco2 = new arcoGrafo();
	G.insArco(citta1,citta2,arco2,biglietto);

	citta1 = ricercaCitta("BA",G);
	citta2 = ricercaCitta("TA",G);
	arcoGrafo *arco3 = new arcoGrafo();
	biglietto.setEuro(7.25);
	biglietto.setMinuti(56);
	G.insArco(citta1,citta2,arco3,biglietto);

	citta1 = ricercaCitta("TA",G);
	citta2 = ricercaCitta("BA",G);
	arcoGrafo *arco4 = new arcoGrafo();
	G.insArco(citta1,citta2,arco4,biglietto);
}

void inserisciArchi2(Mappa &G) {
	NodoGrafo *citta1, *citta2;
	Collegamenti biglietto;

	citta1 = ricercaCitta("TA",G);
	citta2 = ricercaCitta("BR",G);
	arcoGrafo *arco1 = new arcoGrafo();
	biglietto.setEuro(6.24);
	biglietto.setMinuti(63);
	G.insArco(citta1,citta2,arco1,biglietto);

	citta1 = ricercaCitta("BR",G);
	citta2 = ricercaCitta("TA",G);
	arcoGrafo *arco2 = new arcoGrafo();
	G.insArco(citta1,citta2,arco2,biglietto);
}

NodoGrafo* ricercaCitta(string citta, Mappa &G) {
	NodoLista<NodoGrafo*> *pos;
	NodoGrafo* elem = NULL;
	if (!cittaPresente(citta,G))
		cout << "Errore: la citta non fa parte della Mappa"<<endl;
	else {
		pos = G.listaNodi.primoLista();
		elem = G.listaNodi.leggiLista(pos);
		while (citta != elem->getInfo()) {
			pos = G.listaNodi.succLista(pos);
			elem = G.listaNodi.leggiLista(pos);
		}
	}
	return elem;
}

arcoGrafo* ricercaArco(NodoGrafo*c1,NodoGrafo*c2,Mappa &G) {
	arcoGrafo *arco = NULL;
	NodoLista<arcoGrafo*> *pos;
	boolean condizione;

	pos = G.listaArchi.primoLista();
	arco = G.listaArchi.leggiLista(pos);
	condizione= (arco->getNodoPartenza()->getInfo() == c1->getInfo())
			&&( arco->getNodoArrivo()->getInfo() == c2->getInfo());

	while (!condizione && !G.listaArchi.listaVuota()) {
		G.listaArchi.cancLista(pos);
		pos = G.listaArchi.primoLista();
		arco = G.listaArchi.leggiLista(pos);
		condizione= (arco->getNodoPartenza()->getInfo() == c1->getInfo())
				&& (arco->getNodoArrivo()->getInfo() == c2->getInfo());
	}
	return arco;
}

Lista<elem,NodoLista<elem>*> cittaCollegate (NodoGrafo *c1, Mappa G) {
	Lista<NodoGrafo*,NodoLista<NodoGrafo*>*> adiacenti = G. adiacenti(c1);
	Lista<elem,NodoLista<elem>*> lista;
	NodoLista<NodoGrafo*> *pos = adiacenti.primoLista();
	elem elemento;

	if (adiacenti.listaVuota()) {
		cout << "Non sono presenti Collegamenti per questa citta.";
		cout << endl << endl;

	}

	else {
		cout << endl << c1->getInfo() << " E COLLEGATA CON: ";
		cout << endl << endl << " citta    min     costo" << endl;
		NodoGrafo* c2;
		while (! adiacenti.listaVuota()) {
			c2 = adiacenti.leggiLista(pos);
			elemento = aggiornaElem(c1,c2,G);
			lista.insLista(elemento,lista.primoLista());
			adiacenti.cancLista(pos);
			pos = adiacenti.succLista(pos);
		}
	}

	return lista;
}

elem aggiornaElem(NodoGrafo* part,NodoGrafo* arr,Mappa G) {
	/*
	 * Ricerca nella listaArchi l'arco cui collega le due
	 * citta date in Input e associa le informazioni di tale
	 * arco a "elem"
	 */
	arcoGrafo *arco = ricercaArco(part,arr,G);
	Collegamenti info;
	elem elemento;
	info = arco->getInfoArco();
	info = arco->getInfoArco();
	elemento.citta = arr;
	elemento.infoBiglietto = info;

	return elemento;
}

void stampaLista(Lista<elem,NodoLista<elem>*> lista) {
	NodoLista<elem> *pos= lista.primoLista();
	elem elemento;
	if (!lista.listaVuota()) {
        while(!lista.fineLista(pos)) {
        	elemento = lista.leggiLista(pos);
        	cout << endl;
            stampaElem(elemento);
            pos = lista.succLista(pos);
        }
    }
	system("pause");
}

void stampaElem(elem el) {
	cout << "    " << el.citta->getInfo() << "  ";
	cout << "   " << el.infoBiglietto.getMinuti() << "  ";
	cout << "    "<< el.infoBiglietto.getEuro() << endl << endl;
}

boolean cittaPresente(string citta, Mappa &G) {
	NodoLista<NodoGrafo*> *pos = G.listaNodi.primoLista();
	NodoGrafo* x = new NodoGrafo();
	while(!G.listaNodi.fineLista(pos)) {
        x = G.listaNodi.leggiLista(pos);
        if (x->getInfo() == citta)
        	return true;

        pos = G.listaNodi.succLista(pos);
	}
	return false;
}
