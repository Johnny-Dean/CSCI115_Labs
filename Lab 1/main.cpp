#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array ourArr;
    ourArr.addStart(32);
    ourArr.addStart(23);
    ourArr.addStart(31231);
    ourArr.addStart(32);
    ourArr. printArr();
    ourArr.reverseArr();
    ourArr.printArr();
    cout << "Size before: " << ourArr.showSize() << endl;
    ourArr.addEnd(3);
    cout << "Size after: " << ourArr.showSize() << endl;
    ourArr.printArr();
    ourArr.removeStart();
    ourArr.printArr();
    ourArr.removeEnd();
    ourArr.printArr();
    cout << "Sum of array: " << ourArr.sumArr() << endl;
    int* oddArray = ourArr.oddArr();
    cout << "Printing our odd array" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << oddArray[i] << " ";
    }
    cout << endl;
    ourArr.fileArr(ourArr.arrData, ourArr.arrSize);
    Array secondArr;
    secondArr.addStart(2);
    secondArr.addStart(122);
    secondArr.addStart(123192);
    Array combinedArr = ourArr + secondArr;
    combinedArr.printArr();
    return 0;
}
