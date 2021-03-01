//
// Created by Johnny on 2/8/2021.
//

#ifndef LAB3_ARRAYSORT_H
#define LAB3_ARRAYSORT_H
class ArraySort{
public:
    int* myArray;
    int size;

    ArraySort();
    void randomizeArray();
    void printArray();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    int binarysearchIter(int target);
    int binarySearchRec(int l, int r, int target);
};
#endif //LAB3_ARRAYSORT_H
