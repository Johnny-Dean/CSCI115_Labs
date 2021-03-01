//
// Created by Johnny on 1/25/2021.
//

#include "Array.h"
#include <iostream>
#include <fstream>

Array::Array(){
    arrSize = 0;
    arrData = nullptr;
    std::cout << "Default array created" << std::endl;
}

Array::Array(int size) {
    arrSize = size;
    arrData = new int[arrSize];
}

int Array::showSize() {
    return arrSize;
}

void Array::printArr() {

    for(int i = 0; i < arrSize; i++){
        std::cout << arrData[i] << " ";
    }

    std::cout << std::endl;
}

void Array::addStart(int x) {
   arrSize++;
   int* newArr = new int[arrSize];
   for(int i = 1; i < arrSize; i++){
       newArr[i] = arrData[i-1];
   }
   newArr[0] = x;
   arrData = newArr;
}

void Array::addEnd(int x) {
    arrSize++;
    int* newArr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        newArr[i] = arrData[i];
    }
    int* oldArr = arrData;
    newArr[arrSize-1] = x;
    arrData = newArr;
    delete oldArr;
}

void Array::removeStart() {
    if(arrSize==0){
        return;
    }
    arrSize--;
    int* newArr = new int[arrSize];
    for(int i = 0, j = 1; i < arrSize; i++, j++){
        newArr[i] = arrData[j];
    }
    int* oldArr = arrData;
    arrData = newArr;
    delete oldArr;
}

void Array::removeEnd() {
    if(arrSize==0){
        return;
    }
    arrSize--;
    int* newArr = new int[arrSize];
    for(int i = 0; i < arrSize; i++){
        newArr[i] = arrData[i];
    }
    int* oldArr = arrData;
    arrData = newArr;
    delete oldArr;
}

void Array::reverseArr() {
    int* reverseArr = new int[arrSize];
    for (int i = arrSize - 1, j = 0; i>=0; i--, j++) {
        reverseArr[j] = arrData[i];
    }
    int* oldArr = arrData;
    arrData = reverseArr;
    delete oldArr;
}

int Array::sumArr() {
    int res = 0;
    for (int i = 0; i < arrSize; i++) {
        res += arrData[i];
    }
    return res;
}

int* Array::oddArr() {
    int oddSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arrData[i] % 2 != 0){
            ++oddSize;
        }
    }
    std::cout << "How many odd numbers we have: " << oddSize << std::endl;
    int* oddArr = new int[oddSize];
    for (int i = 0, j = 0; j < oddSize; i++) {
        if (arrData[i]%2!=0){
            std::cout << "This is what we are placing into our odd array: " << arrData[i] << std::endl;
            oddArr[j] = arrData[i];
            j++;
        }
    }
    return oddArr;
}

void Array::fileArr(int* arr, int arrSize){
    std::ofstream MyFile("array.txt");
    for (int i = 0; i < arrSize; ++i) {
        MyFile << arr[i] << " ";
    }
    MyFile.close();
}

Array Array::operator+(Array arrTwo) {
    Array combinedArray;
    int i = 0;

    int newSize = this->arrSize + arrTwo.arrSize;
    combinedArray.arrSize = newSize;

    int* newArr = new int[newSize];
    for (; i < this->arrSize; ++i) {
        newArr[i] = this->arrData[i];
    }
    for (int j = 0; j < arrTwo.arrSize; j++, i++) {
        newArr[i] = arrTwo.arrData[j];
    }
    combinedArray.arrData = newArr;
    return combinedArray;
}