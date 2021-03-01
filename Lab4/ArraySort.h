//
// Created by Johnny on 2/22/2021.
//

#ifndef LAB4_ARRAYSORT_H
#define LAB4_ARRAYSORT_H
class ArraySort{
public:
    int* myArray;
    int size;

    ArraySort();
    void mergeSorted(int low, int high);
    void merge(int low, int mid, int high);
    void printArray();
    void quickSort(int low, int high);
    int qsPartition(int low, int high);
};
#endif //LAB4_ARRAYSORT_H
