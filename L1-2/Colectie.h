//
// Created by Stejeroiu Aura on 3/20/2020.
//

#ifndef LAB1_COLECTIE_H
#define LAB1_COLECTIE_H

#endif //LAB1_COLECTIE_H

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
    //capacitate
    int cp;

    //dimensiune
    int n;

    //elemente
    TElem *e;

    //pentru redimensionare
    void redim();

public:
    //constructorul implicit
    Colectie();

    //adauga un element in colectie
    void adauga(TElem e);

    //sterge o aparitie a unui element din colectie
    //returneaza adevarat daca s-a putut sterge
    bool sterge(TElem e);

    //verifica daca un element se afla in colectie
    bool cauta(TElem elem) const;

    //returneaza numar de aparitii ale unui element in colectie
    int nrAparitii(TElem elem) const;


    //intoarce numarul de elemente din colectie;
    int dim() const;

    //verifica daca colectia e vida;
    bool vida() const;

    //returneaza un iterator pe colectie
    IteratorColectie iterator() const;

    // destructorul colectiei
    ~Colectie();


};

class Iterator {

private:

    //iteratorul contine o referinta catre container
    const Colectie& c;

    //pozitia curenta in iterator
    int curent;

    //varianta 2
    //TElem *curent; //pointer spre un element din colectie

public:

    //constructor
    Iterator(const Colectie&);

    //operatii pe iterator
    void prim();

    void urmator();

    TElem element() const;

    bool valid() const;

};