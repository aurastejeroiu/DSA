// 13. ADT SortedMultiMap – using a BST with linked representation with dynamic allocation. In
// the BST unique keys are stored with a dynamic array of the associated values.
#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <crtdbg.h>
#include <assert.h>

using namespace std;
using namespace std::chrono;

bool relation(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testKeySet() {
	SortedMultiMap smm = SortedMultiMap(relation);

	smm.add(1, 100);
	smm.add(2, 200);
	smm.add(3, 300);
	smm.add(1, 500);
	smm.add(2, 600);
	smm.add(4, 800);

	vector<TKey> keySet = smm.keySet();
	assert(keySet.size() == 4);
	assert(keySet[0] == 1);
	assert(keySet[1] == 2);
	assert(keySet[2] == 3);
	assert(keySet[3] == 4);
}

int main() {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	// Run the set of tests from ShortTest.cpp
	testAll();
	cout << "All Short Tests Passed.\n";

	// Run the set of tests from ExtendedTest.cpp
	testAllExtended();
	cout << "All Extended Tests Passed.\n";

	// Test the keySet() method.
	testKeySet();
	cout << "keySet() Test Passed.\n";

	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << "Total runtime: " << duration << " ms.\n";

	system("pause");

	_CrtDumpMemoryLeaks();
	return 0;
}