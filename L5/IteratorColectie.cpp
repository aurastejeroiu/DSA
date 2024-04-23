#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	//O(1)
	curent = c.prim;
}

TElem IteratorColectie::element() const {
	//O(1)
	return col.elem[curent];
}

bool IteratorColectie::valid() const {
	//O(1)
	return curent!=-1;
}

void IteratorColectie::urmator() {
	//O(1)
	curent = col.urm[curent];
}

void IteratorColectie::prim() {
	//O(1)
	curent = col.prim;
}