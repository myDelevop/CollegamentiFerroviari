/*
 * collegamentiFerroviari.h
 *
 *  Created on: 13/gen/2015
 *      Author: rocco
 */

#ifndef COLLEGAMENTIFERROVIARI_H_
#define COLLEGAMENTIFERROVIARI_H_

#include <iostream>
using namespace std;

class Collegamenti {
public:
	void setMinuti(int);
	void setEuro(float);
	int getMinuti();
	float getEuro();
private:
	int minuti;
	float euro;
};

#endif /* COLLEGAMENTIFERROVIARI_H_ */
