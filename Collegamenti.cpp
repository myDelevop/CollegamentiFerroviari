/*
 * CollegamentiFerroviari.cpp
 *
 *  Created on: 13/gen/2015
 *      Author: rocco
 */

#include "Collegamenti.h"

void Collegamenti::setMinuti(int min) {
	minuti = min;
}

void Collegamenti::setEuro(float prezzo) {
	euro = prezzo;
}

int Collegamenti::getMinuti() {
	return minuti;
}

float Collegamenti::getEuro() {
	return euro;
}
