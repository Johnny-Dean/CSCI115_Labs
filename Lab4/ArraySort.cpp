//
// Created by Johnny on 2/22/2021.
//
#include <cstdlib>
#include <iostream>
#include "ArraySort.h"
//Initialize our array with 10, set the seed or random to 10, fill in the array randomly
ArraySort::ArraySort() {
    size = 10;
    srand(10);
    myArray = new int[size];
    for (int i = 0; i < size; i++){
        myArray[i] = rand()%100+1;
    }
}
//Prints array
void ArraySort::printArray() {
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
}
//This is what creates two seperate arrays and compares them while inserting them back into our main array.
void ArraySort::merge(int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++){
        leftArr[i] = myArray[low+i];
    }
    for (int j = 0; j < n2; j++){
        rightArr[j] = myArray[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            myArray[k++] = leftArr[i++];
            i++;
        }
        else{
            myArray[k++] = rightArr[j++];
        }
    }

    while(i < n1){
        myArray[k++] = leftArr[i++];
    }

    while (j < n2){
        myArray[k++] = rightArr[j++];
    }

}
//Starts the recursion
void ArraySort::mergeSorted(int low, int high) {
   if(low<high){
       int middle = (low + high)/2;
       mergeSorted(low, middle);
       mergeSorted(middle + 1,high);
       merge(low, middle,high);
   }
}
//Starts the recursion with our pivot
void ArraySort::quickSort(int low, int high) {
    if(low < high){
        int pivot = qsPartition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot+1, high);
    }

}
// Returns our pivot and also swaps our numbers into place
int ArraySort::qsPartition(int low, int high) {
    int pivot = myArray[low];
    int pIndex = low+1;

    for (int i = low+1; i<=high;i++){
        if(myArray[i] < pivot){
            std::swap(myArray[pIndex],myArray[i]);
            pIndex++;
        }
    }
    std::swap(myArray[low], myArray[pIndex-1]);
    return pIndex - 1;
}



