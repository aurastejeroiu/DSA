#pragma once
#include<vector>
#include<utility>
#define MAX 13

using namespace std;

typedef int TCheie;
typedef int TValoare;

typedef std::pair<TCheie, TValoare> TElem;

class IteratorMD;
class Nod;
typedef Nod* PNod;

class Nod
{

private:
	TElem el;
	PNod urm;
public:
	friend class MD;
	friend class IteratorMD;
	Nod(TElem elem, PNod urmat);
	TElem getElem();
	PNod getUrm();
	void setUrm(PNod urmNou);

};

class MD
{
	friend class IteratorMD;

private:
	int m;
	PNod l[MAX];
	int dF(TElem element) const;

public:
	// constructorul implicit al MultiDictionarului
	MD();

	// adauga o pereche (cheie, valoare) in MD	
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MD 
	int dim() const;

	//verifica daca MultiDictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe MD
	IteratorMD iterator() const;

	// destructorul MultiDictionarului	
	~MD();



};

