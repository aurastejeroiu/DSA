#include "TestScurt.h"
#include "Colectie.h"
#include "IteratorColectie.h"
#include <assert.h>
#include <exception>

using namespace std;

void testAll() {
	Colectie c;
	assert(c.vida() == true);
	c.adauga(5);
	c.adauga(6);
	c.adauga(0);
	c.adauga(5);
	c.adauga(10);
	c.adauga(8);

	assert(c.dim() == 6);
	assert(c.nrAparitii(5) == 2);

	assert(c.sterge(5) == true);
	assert(c.dim() == 5);

	assert(c.cauta(6) == true);
	assert(c.vida() == false);

	IteratorColectie ic = c.iterator();
	assert(ic.valid() == true);
	while (ic.valid()) {
		ic.element();
		ic.urmator();
	}
	assert(ic.valid() == false);
	ic.prim();
	assert(ic.valid() == true);

}

void testFctNoua()
{
	Colectie c;
	assert(c.vida() == true);
	c.adauga(5);
	c.adauga(6);
	c.adauga(5);
	c.adauga(0);
	c.adauga(5);
	c.adauga(10);
	c.adauga(5);
	c.adauga(8);
	c.adauga(5);

	assert(c.dim() == 9);

	try {
		c.eliminaAparitii(-3, 6);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(c.nrAparitii(5) == 5);
	auto eliminate = c.eliminaAparitii(2, 5);
	assert(eliminate == 2);
	assert(c.dim() == 7);
	assert(c.nrAparitii(5) == 3);

	eliminate = c.eliminaAparitii(10, 5);
	assert(eliminate == 3);
	assert(c.dim() == 4);
	assert(c.nrAparitii(5) == 0);
}
