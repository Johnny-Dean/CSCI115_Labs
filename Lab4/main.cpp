#include <iostream>
#include "ArraySort.h"
int main() {
    auto* test = new ArraySort;
    test->printArray();
    test->mergeSorted(0,test->size-1);
    test->printArray();
    auto* test2 = new ArraySort;
    test2->printArray();
    test2->quickSort(0, test->size-1);
    test2->printArray();

    return 0;
}
