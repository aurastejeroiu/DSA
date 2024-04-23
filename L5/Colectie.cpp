#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>
#include <exception>
using namespace std;

bool rel(TElem e1, TElem e2) {
	//O(1)
	return e1 <= e2;
}


int Colectie::aloca()
{
	//O(1)
	int i = primLiber;
	primLiber = urm[primLiber];
	return i;
}

void Colectie::initSpatiuLiber()
{
	//Theta(n)
	for (int i = 0; i < cap; i++)
		urm[i] = i + 1;
	urm[cap - 1] = -1;
}

void Colectie::dealoca(int i)
{
	//O(1)
	urm[i] = primLiber;
	primLiber = i;
}

int Colectie::creazaNod(TElem e)
{
	//O(n)
	if (primLiber == -1)
		redimensionare();
	int i = aloca();
	elem[i] = e;
	urm[i] = -1;
	pre[i] = -1;
	return i;
}

void Colectie::redimensionare()
{
	//Theta(n)
	TElem* elem_nou = new TElem[2 * cap];
	int* urm_nou = new int[2 * cap];
	int* pre_nou = new int[2 * cap];
	for(int i=0;i<cap;i++){
		elem_nou[i] = elem[i];
		urm_nou[i] = urm[i];
		pre_nou[i] = pre[i];
	}
	//urm_nou[cap-1] = cap;
	for (int i = cap; i < cap * 2; i++)
		urm_nou[i] = i + 1;
	urm_nou[cap * 2 - 1] = -1;
	delete[]elem;
	delete[]urm;
	delete[]pre;
	elem = elem_nou;
	urm = urm_nou;
	pre = pre_nou;
	primLiber = cap;
	cap *= 2;
}

Colectie::Colectie() {
	//Theta(n)
	cap = 5;
	elem = new TElem[cap];
	urm = new int[cap];
	initSpatiuLiber();
	pre = new int[cap];
	prim = -1;
	ultim = -1;
	primLiber = 0;
}

void Colectie::adauga(TElem e) {
	//O(n)
	int nou = creazaNod(e);
	if (vida()&&nou==0) {
		prim = nou;
		ultim = nou;
	}	
	else {
		if (rel(e, elem[prim])) {
			pre[nou] = -1;
			urm[nou] = prim;
			pre[prim] = nou;
			if (urm[prim] == nou)
				urm[prim] = primLiber;
			prim = nou;
		}
		else {
			if (rel(elem[ultim], e)) {
				urm[nou] = -1;
				pre[nou] = ultim;
				urm[ultim] = nou;
				ultim = nou;
			}
			else {
				int i = prim;
				while (rel(e, elem[i])==false && i != ultim)
					i = urm[i];
				urm[nou] = i;
				pre[nou] = pre[i];
				pre[i] = nou;
				urm[pre[nou]] = nou;
				if (urm[i] == nou)
					urm[i] = primLiber;
			}
			
		}
	}
}


bool Colectie::sterge(TElem e) {
	//O(n)
	if(cauta(e)==false)
		return false;
	bool deleted= false;
	if (elem[prim] == e) {
		pre[urm[prim]] = -1;
		int aux = urm[prim];
		dealoca(prim);
		prim = aux;
		deleted = true;
		return deleted;
	}
	else {
		if (elem[ultim] == e) {
			urm[pre[ultim]] = -1;
			int aux = pre[ultim];
			dealoca(ultim);
			ultim = aux;
			deleted = true;
			return deleted;
		}
		else {
			int i = prim;
			while (e != elem[i])
				i = urm[i];
			int after = urm[i];
			int before = pre[i];
			pre[after] = before;
			urm[before] = after;
			dealoca(i);
			deleted = true;
			return deleted;
		}
	}
}
//!
int Colectie::eliminaAparitii(int nr, TElem e)
{
	//O(n^2)
	if (nr < 0)
		throw exception();
	int nrApar = nrAparitii(e);
	int eliminate = 0;
	int NR = 0;
	if (nr > nrApar)
		NR = nrApar;
	else
		NR = nr;
	while (NR) {
		sterge(e);
		eliminate++;
		NR--;
	}
	return eliminate;
}


bool Colectie::cauta(TElem e) const {
	//Theta(n)
	return nrAparitii(e)!=0;
}


int Colectie::nrAparitii(TElem e) const {
	//Theta(n)
	int i = prim;
	int aparitii = 0;
	while (i != -1) {
		if (elem[i] == e)
			aparitii++;
		i = urm[i];
	}
	return aparitii;
}
//!
void Colectie::tipareste()
{
	//Theta(n)
	//functie ajutatoare
	int i = prim;
	while (i !=-1) {
		cout << elem[i]<<" ";
		i=urm[i];
	}
	cout << endl;
}



int Colectie::dim() const {
	//Theta(n)
	int i = prim;
	int size = 0;
	while (i!=-1) {
		size++;
		i = urm[i];
	}
	return size;
}


bool Colectie::vida() const {
	//O(1)
	return prim == -1 && ultim==-1;
}


IteratorColectie Colectie::iterator() const {
	//O(1)
	return  IteratorColectie(*this);
}






Colectie::~Colectie() {
	delete[]elem;
}