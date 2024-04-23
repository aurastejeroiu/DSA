#pragma once
#include "Multime.h"
class Multime;
typedef int TElem;
//typedef Node* PNod;

class IteratorMultime
{
	friend class Multime;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	//teta(1)
	IteratorMultime(const Multime& m);

	//contine o referinta catre containerul pe care il itereaza
	const Multime& multime;
	/* aici e reprezentarea  specifica a iteratorului */
	PNod curent;

public:

	//reseteaza pozitia iteratorului la inceputul containerului
	//teta(1)
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//teta(1)
	void urmator();
	//caz favorabil=caz defavorabil =caz mediu
	//teta(1)
	void anterior();

	//verifica daca iteratorul e valid (indica un element al containerului)
	//teta(1)
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//teta(1)
	TElem element() const;
};
