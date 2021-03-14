#include <iostream>
#include "fstream"
#include "HashTable.h"
using std::cout;
int main() {
    HashTable test;
    std::ifstream inFile;
    inFile.open(R"(D:\CSCI 115\Lab6\numbers.txt)");
    //Error Check
    if (inFile.fail()){
        std::cerr << "File Opening Failed" << std::endl;
        exit(1);
    }

    int sum = 0;
    int x1,x2,x3,x4,x5,x6,x7;
    while(inFile >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7){
        sum = x1 + x2 + x3 + x4 + x5 + x6 + x7;
        test.insert(sum);
        sum = 0;
    }
    test.display();
    cout << "Sum Exists Find Attempt: " << test.find(156) << std::endl;
    cout << "Sum Exists Find Attempt: " << test.find(181) << std::endl;
    cout << "Sum Exists Find Attempt In Linked List: " << test.find(206) << std::endl;
    cout << "Sum Doesn't Exist Find Attempt: " <<  test.find(2123123123) << std::endl;
    return 0;
}
