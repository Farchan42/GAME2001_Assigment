#include <iostream>
#include "UnorderedArray.h"
#include "OrderedArray.h"

int main() {
    UnorderedArray<int> unorderedArray;
    unorderedArray.push(5);
    unorderedArray.push(3);
    unorderedArray.push(8);

    std::cout << "Unordered Array Size: " << unorderedArray.getSize() << std::endl;

    OrderedArray<int> orderedArray;
    orderedArray.push(5);
    orderedArray.push(3);
    orderedArray.push(5); // Duplicate, should not be added
    orderedArray.push(8);

    std::cout << "Ordered Array Size: " << orderedArray.getSize() << std::endl;

    return 0;
}