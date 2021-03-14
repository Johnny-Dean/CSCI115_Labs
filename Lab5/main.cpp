#include <iostream>
#include "DoubleLinkedLists.h"
using namespace std;
int main() {
    DLL test;
    test.insertBeg(2);
    test.insertBeg(3);
    test.insertBeg(4);
    test.insertBeg(5);
    cout << "For loop print: " << endl;
    test.printFor();
    cout << "While loop print: " << endl;
    test.printWhile();
    cout << "Recursion print: " << endl;
    node* current = test.head;
    test.printRec(current);
    test.insertEnd(1);
    cout << "Insert end: " << endl;
    test.printWhile();
    cout << "Delete beginning: " << endl;
    test.removeBeg();
    test.printWhile();
    cout << "Delete end: " << endl;
    test.removeEnd();
    test.printWhile();

    DLL sortedTest;
    sortedTest.insertEnd(5);
    sortedTest.insertEnd(7);
    sortedTest.insertEnd(8);
    sortedTest.insertEnd(10);
    sortedTest.insertEnd(12);
    cout << "Printing our sorted array: " << endl;
    sortedTest.printWhile();
    sortedTest.insertSortFor(6);
    sortedTest.printWhile();
    sortedTest.insertSortWhile(9);
    sortedTest.printWhile();
    sortedTest.insertSortRec(11, sortedTest.head);
    sortedTest.printWhile();
    cout << "Deleting stuff from our sorted array." << endl;
    sortedTest.deleteSortWhile(8);
    cout << "Deleted 8. | ";
    sortedTest.printWhile();
    sortedTest.deleteSortRec(9, sortedTest.head);
    cout << "Deleted 9. | ";
    sortedTest.printWhile();
    cout << "Deleted 10, | ";
    sortedTest.deleteSortFor(10);
    sortedTest.printWhile();
    return 0;
}
