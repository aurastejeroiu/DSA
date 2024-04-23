#pragma once

#define NULL_TELEM -1
typedef int TElem;
class Node;
typedef Node* PNod;

class IteratorMultime;
class Multime;
class Node {
public:
	friend class Multime;
	//teta(1)
	Node(TElem elem, PNod urm, PNod ant);
	//teta(1)
	TElem element();
	//teta(1)
	PNod urmator();
	//teta(1)
	PNod anterior();



private:
	TElem e;
	PNod urm;
	PNod ant;
};




class Multime {
	friend class IteratorMultime;

private:
	/* aici e reprezentarea */
	PNod prim;
public:
	//constructorul implicit
	//teta(1)
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	//O(n)
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	//O(n)
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	//O(n)
	bool cauta(TElem elem) const;


	//intoarce numarul de elemente din multime;
	//O(n)
	int dim() const;

	//verifica daca multimea e vida;
	//teta(1)
	bool vida() const;

	//returneaza un iterator pe multime
	//teta(1)
	IteratorMultime iterator() const;

	// destructorul multimii
	//O(n)
	~Multime();
};









