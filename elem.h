/*
 * elem.h
 *
 *  Created on: 14/gen/2015
 *      Author: Rocco
 */

#ifndef ELEM_H_
#define ELEM_H_

//Vedi 2. PROGETTAZIONE DEI DATI

#include "cellaGrafo.h"
typedef cellaGrafo<string> NodoGrafo;

class elem {
public:
	Collegamenti infoBiglietto;
	NodoGrafo *citta;
};





#endif /* ELEM_H_ */
