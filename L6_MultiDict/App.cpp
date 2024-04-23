#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"

using namespace std;

int main() {

	testAll();
	cout << "Test scurt OK\n";
	testAllExtins();
	cout << "Test extins OK\n";

	cout << "End";
	return 0;
}