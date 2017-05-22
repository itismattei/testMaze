/*
 * Quadrato.h
 *
 *  Created on: 07/mag/2017
 *      Author: tps8
 */

#ifndef QUADRATO_H_
#define QUADRATO_H_

class Quadrato {
public:
	Quadrato();
	Quadrato( const Quadrato& );
	virtual ~Quadrato();

	Quadrato& operator=(const Quadrato & q);


public:

	int mLato[4];
	int mColore;
	int ID;
	int mR;			/// numero riga
	int mC;			/// numero colonna
	int mAngolo;	/// angolo rispetto al  rif assoluto della cella numero 1
};

#endif /* QUADRATO_H_ */
