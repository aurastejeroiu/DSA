#include "IteratorMD.h"
#include "MD.h"
#include <iostream>

using namespace std;

void IteratorMD::deplasare()
{
	//O(n)
	while (poz < md.m && md.l[poz] == nullptr)
		poz++;
	if (poz < md.m)
		curent = md.l[poz];
}

IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	//O(1)
	poz = 0;
	curent = _md.l[poz];
	deplasare();
}

TElem IteratorMD::element() const {
	//O(1)
	//if(!this->valid())
		//throw exception;
	return curent->getElem();
}

bool IteratorMD::valid() const {
	//O(1)
	return (poz < md.m) && (curent != nullptr);
}

void IteratorMD::urmator() {
	//O(n)
	if (this->valid()) {
		curent = curent->urm;
		if (curent == nullptr) {
			poz = poz + 1;
			deplasare();
		}
	}
}



void IteratorMD::prim() {
	//O(n)
	poz = 0;
	deplasare();
}
