/*
 * Quadrato.cpp
 *
 *  Created on: 07/mag/2017
 *      Author: tps8
 */

#include "Quadrato.h"

Quadrato::Quadrato() {
	// TODO Auto-generated constructor stub
	mColore = 0;
	ID = 0;
	mAngolo = 0;
	mC = mR = -100;
}

Quadrato::~Quadrato() {
	// TODO Auto-generated destructor stub
}

/// costruttore di copia
Quadrato::Quadrato( const Quadrato & q){
	if (this != & q){
		mColore = q.mColore;
		for (int i = 0 ; i < 4; i++)
		mLato[i]  = q.mLato[i];
		ID = q.ID;
		mC = q.mC;
		mR = q.mR;
		mAngolo = q.mAngolo;
	}
}

///
/// operatore =
Quadrato& Quadrato::operator=(const Quadrato & q){

	if (this != &q){
		ID = q.ID;
		mC = q.mC;
		mR = q.mR;
		mAngolo = q.mAngolo;
		mColore = q.mColore;
		for (int i = 0; i < 4 ; i++)
			mLato[i] = q.mLato[i];

	}
	return *this;

}
