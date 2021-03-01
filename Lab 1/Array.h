//
// Created by Johnny on 1/25/2021.
//
#ifndef LAB_1_ARRAY_H
#define LAB_1_ARRAY_H
class Array{
public:
    int arrSize; //Array Size
    int* arrData; //Integer Array

    Array(); //Default Constructor
    Array(int);

    int showSize(); // Shows size of array
    void printArr(); // Print array
    void addStart(int);
    void addEnd(int);
    void removeStart();
    void removeEnd();
    void reverseArr();
    int sumArr();
    int* oddArr();
    void fileArr(int* arr, int arrSize);
    Array operator+(Array arrTwo);
};
#endif //LAB_1_ARRAY_H
