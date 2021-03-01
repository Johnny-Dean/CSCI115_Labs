//
// Created by Johnny on 2/22/2021.
//

#ifndef LAB4_ARRAYSORT_H
#define LAB4_ARRAYSORT_H
class ArraySort{
    int* myArray{};
    int size{};

    ArraySort();
    void mergeSorted();
    void quickSort();
    void qsPartition();
    void merge();
};
#endif //LAB4_ARRAYSORT_H
