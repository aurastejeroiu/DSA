#include "IteratorMultime.h"
#include <exception>


IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	/* de adaugat */
	curent = m.prim;
}


void IteratorMultime::prim() {
	/* de adaugat */
	curent = multime.prim;
}


void IteratorMultime::urmator() {
	/* de adaugat */
	curent = curent->urmator();
}

void IteratorMultime::anterior() {

	if (curent == nullptr) {
		throw std::exception();
	}
	else {
		curent = curent->anterior();
	}
}

TElem IteratorMultime::element() const {
	/* de adaugat */
	return curent->element();

}

bool IteratorMultime::valid() const {
	/* de adaugat */
	return curent != nullptr;
}
