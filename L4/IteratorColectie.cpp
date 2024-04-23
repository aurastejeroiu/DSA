#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>


IteratorColectie::IteratorColectie(const Colectie& c) : col(c), currentNode { c.head }, currentFreq{ 1 }
/*{/* de adaugat 
	this->currentNode = c.head;
	this->currentFreq = 1;
}	
*/
TElem IteratorColectie::Getelement() const {
	if (this->valid() == true) {
		return this->currentNode->element;
	}
	else {
		throw std::exception("No");
	}
}

bool IteratorColectie::valid() const {

	if (this->currentNode == NULL) {
		return false;
	}
	return true;
}

void IteratorColectie::next() {
	if (this->valid() == false) {
		throw std::exception("Stop");
	}
	else {
		if (this->currentNode->frequency > this->currentFreq) {
			this->currentFreq += 1;
		}
		else {
			this->currentNode = this->currentNode->next;
			this->currentFreq = 1;
		}
	}

void IteratorColectie::prim() {
	/* de adaugat */
	this->currentNode = this->c.head;
	this->currentFreq = 1;
}

IteratorColectie::~IteratorColectie()
{
}