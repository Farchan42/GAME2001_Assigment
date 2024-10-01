#include "OrderedArray.h"
#include "UnorderedArray.h"

int main() {
    // Create an OrderedArray with duplicate prevention enabled
    OrderedArray<int> orderedArr(2, true);
    orderedArr.push(3);
    orderedArr.push(1);
    orderedArr.push(2);
    orderedArr.push(2);  // Duplicate, should not be added
    orderedArr.push(4);

    // Output: 1 2 3 4
    std::cout << "Ordered Array (No Duplicates): ";
    orderedArr.print();

    // Create an UnorderedArray
    UnorderedArray<int> unorderedArr;
    unorderedArr.push(5);
    unorderedArr.push(3);
    unorderedArr.push(7);

    // Output: 5 3 7
    std::cout << "Unordered Array: ";
    unorderedArr.print();

    return 0;
}
