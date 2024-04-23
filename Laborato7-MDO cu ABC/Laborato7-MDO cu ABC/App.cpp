#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"

int main() {
        testAll();
        std::cout << "Test scurt terminat!" << std::endl;
        testAllExtins();
        std::cout << "Test extins terminat!" << std::endl;
    std::cout << "Finished Tests!" << std::endl;
}