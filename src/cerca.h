/*
 * cercaLato.h
 *
 *  Created on: 20/mag/2017
 *      Author: tps8
 */

#ifndef CERCA_H_
#define CERCA_H_

#include "Quadrato.h"



/// definisco una classe funzione cioè che effettua l'overloadd di ()
/// questo oggetto è un funtore o oggetto funzionale e potra' essere
/// usato come predicato nella find_if. Il predicato della find_if deve essere unario
/// e quindi non può essere del tipo : bool operator()(<typename T> , <typenanme T> ) {return "confronto tra primo e secondo parametro"}
/// Il predicato deve essere del tipo bool operator()(<typename T>){ return ....}
/// Per ottenere ciò che vuole il compilatore occorre quindi che il parametro di confronto per un oggetto generico sia già presente
/// e ciò può accadere se è già nella classe funzionale.
/// Il predicato può essere un puntatore a funzione: bool (* nome)(<typename T>) { return true; .....}, ma non aiuta poiché non si riesce a
/// passare il parametro di confronto. Per far ciò servirebbe un operatore binario che non è ammesso dalla find_if


struct cercaLato {
public:

	/// Il costruttore mi permette di memorizzare nell'oggetto il parametro di confronto
	cercaLato(int valoreLato) : valore(valoreLato) {}
	int valore;
	/// ridefinisco l'operatore()
	bool operator()(Quadrato &q) const { for (int i = 0; i < 4; i++) if (valore == q.mLato[i]) return true;
										return false;}

	~cercaLato();
};

/// Notare l'us di class ppure di struct
struct cercaRiga {
public:

	/// Il costruttore mi permette di memorizzare nell'oggetto il parametro di confronto
	cercaRiga(int valoreR) : valore(valoreR) {}
	int valore;
	/// ridefinisco l'operatore()
	bool operator()(Quadrato &q) const { if (valore == q.mR) return true;
										return false;}

};

///oggettto funzionale per ricerca dei vaori di riga e colonna nella list
class cercaPos{
public:
	cercaPos(int R, int C): riga(R), col(C) {}
	int riga;
	int col;

	/// ridefinizione operatore()
	bool operator()(Quadrato &q) const {if (riga == q.mR && col == q.mC)
										return true;
										else return false;
										}
};

#endif /* CERCA_H_ */
