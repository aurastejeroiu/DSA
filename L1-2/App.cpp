#include <iostream>
#include "Colectie.h"

#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;


    void creare(Colectie& c) {
        for(int i=1; i<=6;i++){
            c.adauga(i);
        }
    }



//tiparire folosind iteratorul
    void tiparire(Colectie& c) {

        i = c.iterator();
        i.prim();
        while (i.valid()) {
            cout << i.element() << ' ';
            i.urmator();
        }

    }


    int main(void) {
        Colectie c(3);
        creare(c);
        tiparire(c);
        return 0;
    }
    //testAllExtins();
    //testAll();
