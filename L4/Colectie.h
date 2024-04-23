#pragma once;
#include "Node.h"
#include "IteratorColectie.h"

typedef int TComp;

typedef TComp TElem;
typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei

class IteratorColectie;

class Colectie {
	friend class IteratorColectie;
private:
	/* aici e reprezentarea */
	Node* head;
	Relatie rel;
	friend class IteratorColectie;
public:
	//constructorul implicit
	Colectie(Relatie r);

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem e) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TComp e) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();


};
