//============================================================================
// Name        : testMaze.cpp
// Author      : max
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdint.h>
#include <ctime>
#include <algorithm>
#include <list>
#include <cstdlib>

#include "Quadrato.h"
#include "cerca.h"

//#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;


int main() {


/* da USARE PER SCHEDULARE I PROCESSI IN UNA MODALITA' SW REAL-TIME */

//    struct timeval start, end;
//
//    long mtime, seconds, useconds;
//
//    gettimeofday(&start, NULL);
//    /// .......
//    /// azioni da svolgere (lettura sensori)
//    /// applicazione algoritmi
//    /// ......
//
//    /// lettura del tempo passat
//
//    gettimeofday(&end, NULL);
//
//    seconds  = end.tv_sec  - start.tv_sec;
//    useconds = end.tv_usec - start.tv_usec;
//
//    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
//
//    /// sleep per il tempo restante a raggiungere 100 ms
//    usleep(100000 - useconds);
//
//    printf("Elapsed time: %ld milliseconds\n", mtime);
//
//    return 0;


	vector<string> Vs;
	/// insieme delle celle che costituiscono il campo di gara ed iteratori di scorrimento e ricerca
	list<Quadrato> Vq, tmp, campoGara;
	list<Quadrato> *ptQ;
	list<Quadrato>::iterator itQuad, itFin;
	/// inserisce gli elementi
	Quadrato ins, read, ins1;

	ptQ = new list<Quadrato>;
	if (ptQ == NULL)
		cout << "allocazione fallita\n";
	/// generatore di numeri casuali ON
	srand(time(NULL));
	cout << "inizializzato il generatore di numeri casuali: " << time(NULL) << endl;

	ins.mColore = 1;
	for (int i = 0; i < 4; i++){
		ins.mLato[i] = i;
	}
	ins.ID = 3;
	/// carica l'elemento cella nella lista Vq
	Vq.push_back(ins);
	ins1.mColore = -13;

	for (int i = 0; i < 4; i++){
			ins1.mLato[i] = i * 3 + 4;
		}
	ins1.ID = 89;
	Vq.push_back(ins1);
	read = ins1;
	read.ID = 90;
	Vq.push_back(read);

	itQuad = Vq.begin();
	itFin = Vq.end();
	int i;
	i = (*itFin).mColore;
	cout << i << endl;
	fstream outF ("pippo.txt", ios::app);
	Vs.push_back("primo");
	Vs.push_back("secondo");
	Vs.push_back("terzo");

	cout << "dimensione del vettore di stringhe " << Vs.size() << endl; // prints !!!Hello World!!!
	outF.close();

	for (uint8_t i = 0; i < Vs.size(); i++)
		cout << Vs[i] << endl;

	/// lettura del vettore con iteratore
	vector<string>::iterator vIteratore;
	for (vIteratore = Vs.begin(); vIteratore != Vs.end(); vIteratore++)
		cout << *vIteratore << endl;


	///  find_if chiama un bool (* nome) (<typename T>) nel caso ordinario.
	///  se il terzo paramentro è un oggetto, allora chiama il metodo operator() dello stesso, che quindi
	///  va ridefinito.
	itQuad = Vq.begin();
	/// deve cercare la presenza di più di un oggetto che risponde al criterio
	while(itQuad != Vq.end()){
		itQuad = find_if(++itQuad, Vq.end(), cercaLato(10));
		if (itQuad != Vq.end()){
			cout << "trovato elemento di ID " << (*itQuad).ID << endl;
			tmp.push_back(*itQuad);
		}
	}
	if (!tmp.empty())
		cout << "trovati n. " << tmp.size() << " elementi e creata lista" << endl;
	else
		cout << "non trovato nulla" << endl;
//	vector<string>::iterator iter;
//	iter = find_if(Vs.begin(), Vs.end(), "terzo");
//	if (iter != Vs.end()){
//		/// ha trovato qualcosa
//		cout << "trovato l'elemento " << *iter << endl;
//		cout << "distanza " << distance(Vs.begin(), iter);
//	}
//	else
//		cout << "non trovato!" << endl;


	/// Come si riesce ad estrarre un elemento da un oggetto dentro una lista?

	vector<int> pippo;
	pippo.push_back(4);
	pippo.push_back(45);
	vector<int>::iterator pp= find(pippo.begin(), pippo.end(), 4);

	/// immettiamo alcune celle  nel campo di gara (al massimo 15)
	int numCelle = rand() % 15 +1;
	cout << " ### " << endl << "immesse n. " << numCelle << " celle" << endl;
	/// carico in maniera casuale le celle nella lista. Le coordinate di colonna e riga sono invece consecutive
	for (int i = 0 ; i < numCelle; i++){
		ins.ID = rand() + 1;
		/// le righe aumentano quando si raggiunge la colonna n. 4
		ins.mR = i / 4 + 1;
		ins.mC = i % 4 + 1;
		/// carica casualmente i muri sui lati
		for (int i = 0; i < 4; i++)
			/// 0 significa lato vuoto
			/// 1 significa lato pieno
			ins.mLato[i] = rand() % 2;
		campoGara.push_back(ins);
		ptQ->push_back(ins);

	}

	/// caricata la lista di celle si provvede ad elencare tutte le celle
	itQuad = campoGara.begin();
	while(itQuad != campoGara.end()){
		cout << "r: " << (*itQuad).mR << " c: " << (*itQuad).mC << " ID: " << (*itQuad).ID << endl;
		++itQuad;
	}

	/// restituisce l'ultimo elemento della lista
//	ins = campoGara.back();
//	/// restituissce l'iteratore successivo all'ultimo elemento
//	itQuad = campoGara.end();
//	/// restituissce l'iteratore all'ultimo elemento
//	--itQuad;
//	/// provo a rimuovere l'ultimo elemento
//	campoGara.erase(itQuad);

	/// cerca la presenza di una cella ad una specifica posizione
	itQuad = campoGara.begin();


	itQuad = find_if(itQuad++, campoGara.end(), cercaPos(2, 1));
	if (itQuad != campoGara.end()){
		/// la cella e' presente
		cout << "cella (2,1) presente " << endl;
		cout << "valore di ID: " << (*itQuad).ID << endl;
		cout << "situazione dei lati: \t";
		for (int i = 0; i < 4; i++)
			cout << i + 1 << ": "<< (*itQuad).mLato[i] << " - ";
		cout << endl;
	}
	else
		cout << "cella non trovata!" << endl;


	itQuad = campoGara.end();
	/// restituissce l'iteratore all'ultimo elemento
	--itQuad;

	/*  ALGORITMO DEL LABIRINTO */
	/*  1. la cella iniziale è la 1,1
	 *  2. continua AVANTI fino al primo muro o cella interdetta
	 *  3. ogni 30 cm aumenta il numero di riga della cella
	 *  4. rotazione a sinistra: angolo -90°, aumnta il numero di colonna e ritorna al punto 2
	 *  5. rotazione a destra: angolo +90°, diminuisce il numero di colonna
	 *  6. casualmente si domanda se ci sono celle vuote da esplorare
	 *  7. sa calcolare un percorso sulla mappa usando le info delle celle esplorate
	 *
	 * */

	return 0;
}


