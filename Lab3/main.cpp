#include <iostream>
#include "ArraySort.h"
int main() {
    ArraySort test;
    test.printArray();
    test.bubbleSort();
    std::cout << "Sorted: ";
    test.printArray();
    test.randomizeArray();
    test.printArray();
    test.selectionSort();
    std::cout << "Sorted: ";
    test.printArray();
    test.randomizeArray();
    test.printArray();
    test.insertionSort();
    std::cout << "Sorted: ";
    test.printArray();
    ArraySort bSearch;
    bSearch.myArray[0] = 1;
    bSearch.myArray[1] = 2;
    bSearch.myArray[2] = 3;
    bSearch.myArray[3] = 4;
    bSearch.myArray[4] = 5;
    bSearch.myArray[5] = 6;
    bSearch.myArray[6] = 7;
    bSearch.myArray[7] = 8;
    bSearch.myArray[8] = 9;
    bSearch.myArray[9] = 10;
    bSearch.myArray[10] = 11;
    bSearch.printArray();
    std::cout << bSearch.binarysearchIter(9);
    std::cout << std::endl;
    std::cout << bSearch.binarySearchRec(0,bSearch.size - 1,9);

    return 0;
}
