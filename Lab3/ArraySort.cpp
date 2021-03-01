//
// Created by Johnny on 2/8/2021.
//
#include <cstdlib>
#include <iostream>

#ifndef LAB_3_ARRAYSORT_H
#define LAB_3_ARRAYSORT_H

#include "ArraySort.h"

ArraySort::ArraySort() {
    size = 10;
    myArray = new int[size];
    for (int i = 0; i < size; ++i) {
        myArray[i] = rand() % 100 + 1;
    }
}

void ArraySort::randomizeArray() {
    for (int i = 0; i < size; ++i) {
        myArray[i] = rand() % 100 + 1;
    }
}

void ArraySort::printArray() {
    for (int i = 0; i < size; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
}
//Bubblesort slowly "bubbles" the largest numbers to the end, comparing j with j+1 and finding the greatest number then swapping.
void ArraySort::bubbleSort() {
    for (int i = 0; i < size-1; ++i) {
        for (int j = 0; j < size-i-1; ++j) {
            if(myArray[j] > myArray[j+1]){
                int temp = myArray[j];
                myArray[j] = myArray[j+1];
                myArray[j+1] = temp;
            }
        } 
    }
}
//Takes the smallest value in the array and moves it to its proper position
void ArraySort::selectionSort() {
    int i, j, min, temp;
    for (i = 0; i < size - 1 ; i++) {
        min = i;
        for (j = i + 1; j < size; j++){
            if(myArray[j] < myArray[min]){
                min = j;
            }
        }
        temp = myArray[i];
        myArray[i] = myArray[min];
        myArray[min] = temp;
    }
}

//Insertion sort compare to the numbers at the left of it and keep swapping till in sorted order
void ArraySort::insertionSort() {
    for (int i = 1; i < size; ++i) {
        int key = myArray[i];
        int j = i - 1;

        while (j >= 0 && myArray[j] > key){
            myArray[j+1] = myArray[j];
            j--;
        }
        myArray[j+1] = key;
    }
}
//Split the array in half each time and see if the target is the middle, eventually splits to one, if not we dont have it in the array
int ArraySort::binarysearchIter(int target) {
    int start = 0;
    int end = size - 1;
    while (start <= end){ // While a middle still exists
        int middle = start + (end-start) / 2;
        // check if the middle is our target
        if (myArray[middle] == target){return middle;}
        // if x is greater, ignore the left half
        if (myArray[middle] < target){start = middle+1;}
            //if x is less, ignore the right half;
        else{end=middle-1;}
    }
    return -1; // <-- If the loop exited to this it means that the while loop failed to find the number we wanted.
}
//Split the array in half each time and see if the target is the middle, eventually splits to one, if not we dont have it in the array

int ArraySort::binarySearchRec(int l, int r, int target) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (myArray[mid] == target)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (myArray[mid] > target){
            return binarySearchRec(l, mid - 1, target);
        }
        else{
            // Else the element can only be present
            // in right subarray
            return binarySearchRec(mid + 1, r, target);
        }
    }
    // We reach here when element is not
    // present in array
    return -1;
}


#endif

