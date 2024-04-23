#pragma once;
#include "IteratorColectie.h"
typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Colectie {

	friend class IteratorColectie;

private:
	int cap;
	TElem* elem;
	int* urm;
	int* pre;
	int prim;
	int ultim;
	int primLiber;

	int aloca();
	void initSpatiuLiber();
	void dealoca(int i);
	int creazaNod(TElem e);
	void redimensionare();
public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//functionalitate noua
	int eliminaAparitii(int nr, TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem e) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem e) const;

	void tipareste();

	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

};
