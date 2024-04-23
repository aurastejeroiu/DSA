#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

/*
bool rel(TElem e1, TElem e2) {
	/* de adaugat 
	return false;
}
*/

Colectie::Colectie(Relatie r) {
	this->head = NULL;
	this->rel = r;
}

void Colectie::adauga(TComp e) {
	{
		Node* currentNode = this->head;
		if (this->head == NULL) { //meaning that the list is empty, we want to add at the beginning
			Node* auxNode = new Node;
			auxNode->element = e;
			auxNode->frequency = 1;
			auxNode->next = this->head;
			this->head = auxNode;
		}
		else {
			if (this->cauta(e) == true) { //the element is already present in the bag
				while (currentNode != NULL) {
					if (currentNode->element == e) {
						currentNode->frequency += 1;
						break;
					}
					currentNode = currentNode->next;
				}
			}
			else {
				while (currentNode->next != NULL) {
					if (this->rel(currentNode->element, e) == false) {
						if (currentNode == this->head) {
							Node* auxNode = new Node;
							auxNode->element = e;
							auxNode->frequency = 1;
							auxNode->next = currentNode;
							this->head = auxNode;
							break;
						}
					}
					else if (this->rel(currentNode->next->element, e) == false) {
						Node* auxNode = new Node;
						auxNode->element = e;
						auxNode->frequency = 1;
						auxNode->next = currentNode->next;
						currentNode->next = auxNode;
						break;
					}
					currentNode = currentNode->next;
				}
				if (currentNode->next == NULL) {
					//inserting at the end of the bag
					Node* auxNode = new Node;
					auxNode->element = e;
					auxNode->frequency = 1;
					auxNode->urmattor = NULL;
					currentNode->next = auxNode;
				}
			}
		}
	}


bool Colectie::sterge(TComp e) {
	Node* currentNode = this->head;
	Node* prevNode = NULL;
	if (this->cauta(e) == true) {
		if (this->nrAparitii(e) == 1) {
			while (currentNode != NULL && currentNode->element != e) {
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			if (currentNode != NULL && prevNode == NULL) {
				this->head = this->head->next;
			}
			else if (currentNode != NULL) {
				prevNode->next = currentNode->next;
				currentNode->next = NULL;
			}
		}
		else {
			while (currentNode != NULL) {
				//dunno if this one is oke
				if (currentNode->element == e) {
					currentNode->frequency -= 1;
					break;
				}
				currentNode = currentNode->next;
			}
		}
		return true;
	}
	else {
		return false;
	}
}


bool Colectie::cauta(TComp e) const {
	/* de adaugat */
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->element == e) {
			return true;
		}
		currentNode = currentNode->next;
	}
	return false;
}


int Colectie::nrAparitii(TComp e) const {
	Node* currentNode = this->head;
	if (this->cauta(e) == true) {
		while (currentNode != NULL) {
			if (currentNode->element == e) {
				return currentNode->frequency;
			}
			currentNode = currentNode->next;
		}
	}
	else {
		return 0;
	}
}
}



int Colectie::dim() const {
	int s = 0;
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		s += currentNode->frequency;
		currentNode = currentNode->next;
	}
	return s;
}


bool Colectie::vida() const {
	if (this->dim() == 0) {
		return true;
	}
	else {
		return false;
	}
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
}