#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

Node::Node(TElem elem, PNod urm, PNod ant) {
	this->e = elem;
	this->urm = urm;
	this->ant = ant;
}

TElem Node::element() {
	return this->e;
}

PNod Node::urmator() {
	return this->urm;
}

PNod Node::anterior() {
	return this->ant;
}


Multime::Multime() {
	/* de adaugat */
	this->prim = nullptr;
}


bool Multime::adauga(TElem elem) {
	/* de adaugat */
	if (prim == nullptr)
	{
		prim = new Node(elem, nullptr, nullptr);
		return true;
	}
	PNod x = prim;
	while (x != nullptr)
	{
		if (x->e == elem) {
			return false;
		}
		x = x->urm;
	}
	PNod newN = new Node(elem, nullptr, nullptr);
	newN->urm = prim;
	prim->ant = newN;
	newN->ant = nullptr;
	prim = newN;
	return true;
}


bool Multime::sterge(TElem elem) {
	if (prim == nullptr)
		return false;
	//stergem primul nod
	PNod x = prim;
	if (x->e == elem)
	{
		PNod aux;
		aux = x;
		prim = prim->urm;
		if (prim != nullptr)
			prim->ant = nullptr;
		delete aux;
		return true;
	}

	while (x != nullptr)
	{
		if (x->e == elem) {

			if (x->urm == nullptr)
			{
				PNod aux = x;
				x->ant->urm = nullptr;
				delete aux;
				return true;
			}
			else
			{
				PNod aux = x;
				x->ant->urm = x->urm;
				x->urm->ant = x->ant;
				delete aux;
				return true;
			}

		}
		x = x->urm;
	}
	return false;
}


bool Multime::cauta(TElem elem) const {
	/* de adaugat */
	PNod x = prim;
	while (x != nullptr)
	{
		if (x->e == elem) {

			return true;
		}
		x = x->urm;
	}
	return false;
}


int Multime::dim() const {
	/* de adaugat */
	PNod x = prim;
	int len = 0;
	while (x != nullptr)
	{
		len++;
		x = x->urm;
	}
	return len;
}

bool Multime::vida() const {
	/* de adaugat */
	if (prim == nullptr)
		return true;
	return false;
}


Multime::~Multime() {
	/* de adaugat */
	PNod aux;
	while (prim != nullptr)
	{
		aux = prim;
		prim = prim->urm;
		delete aux;

	}
	prim = nullptr;
}



IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

