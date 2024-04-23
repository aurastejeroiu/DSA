#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem elem, PNod urmat)
{
	//O(1)
	this->el = elem;
	this->urm = urmat;
}

TElem Nod::getElem()
{
	//O(1)
	return this->el;
}

PNod Nod::getUrm()
{
	//O(1)
	return this->urm;
}

void Nod::setUrm(PNod urmNou)
{
	//O(1)
	this->urm = urmNou;
}

int hashCode(TElem element) {
	//O(1)
	return abs(element.first);
}


int MD::dF(TElem element) const
{
	return hashCode(element) % m;
}

MD::MD(){
	//Theta(m)
	m = MAX;
	for (int i = 0; i < m; i++) {
		l[i] = nullptr;
	}
}


void MD::adauga(TCheie c, TValoare v) {
	//O(1)
	TElem e = make_pair(c,v);
	auto poz = dF(e);
	//cazul 1. cand lista l este necompletata pe pozitia poz (l[poz]==nullptr)
	if (l[poz] == nullptr) {
		PNod pnod = new Nod(e, nullptr);
		l[poz] = pnod;
	}
	else {
		//cazul 2. cand lista l contine deja o succesiune de noduri in pozitia l[poz] (l[poz]!=nullptr)
		PNod cap = l[poz];
		l[poz] = new Nod(e, cap);
	}
}


bool MD::sterge(TCheie c, TValoare v) {
	//O(n)
	TElem e = make_pair(c, v);
	auto poz = dF(e);
	//daca pozitia din TD unde trebuie sa fie memorat elementul nu este ocupata (este goala) returnam fals
	if (l[poz] == nullptr)
		return false;
	else {
		//daca elementul se afla pe prima pozitie in lista corespunzatoare pozitiei poz din TD
		if (l[poz]->getElem() == e)
			if (l[poz]->getUrm() == nullptr) {
				//daca este singurul din lista
				l[poz] = nullptr;
				return true;
			}
			else {
				//daca lista are mai mult de un element
				l[poz] = l[poz]->getUrm();
				return true;
			}
		else {
			//daca elementul nu se afla in capul listei
			auto cap = l[poz];
			int i = 0;
			//determinam pozitia lui in lista
			while (cap!=nullptr && cap->getElem() != e) {
				cap = cap->getUrm();
				i++;
			}
			//parcurgem lista si ne pozitionam pe elementul precedent celui care se doreste a fi sters
			if (cap != nullptr) {
				cap = l[poz];
				while (i > 1) {
					cap = cap->getUrm();
					i--;
				}
				auto deSters = cap->getUrm();
				cap->setUrm(deSters->getUrm());
				return true;
			}
			//nu am gasit elementul in lista
			else
				return false;
		}
	}
}


vector<TValoare> MD::cauta(TCheie c) const {
	//Theta(n/m)
	vector<TValoare> valori;
	TElem e = make_pair(c, 0);
	auto poz = dF(e);
	auto cap = l[poz];
	while (cap != nullptr) {
		if(cap->getElem().first==c)
			valori.push_back(cap->getElem().second);
		cap = cap->getUrm();
	}
	return valori;	
}


int MD::dim() const {
	//Theta(n)
	int dim = 0;
	for (int i = 0; i < m; i++) {
		if (l[i] != nullptr) {
			auto cap = l[i];
			while (cap != nullptr) {
				++dim;
				cap = cap->getUrm();
			}
		}
	}
	return dim;
}


bool MD::vid() const {
	//Theta(n)
	for (int i = 0; i < m; i ++) {
		if (l[i] != nullptr)
			return false;
	}
	return true;
}

IteratorMD MD::iterator() const {
	return IteratorMD(*this);
}


MD::~MD() {
	//se elibereaza memoria alocata listelor
	for (int i = 0; i < m; i++) {
		//se elibereaza memoria pentru lista i
		while (l[i] != nullptr) {
			PNod p = l[i];
			l[i] = l[i]->urm;
			delete p;
		}
	}
}