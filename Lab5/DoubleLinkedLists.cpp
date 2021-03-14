//
// Created by Johnny on 3/7/2021.
//

#include <iostream>
#include "DoubleLinkedLists.h"
//Constructor
DLL::DLL() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
//Destructor
DLL::~DLL() {
    while(size!=0){
        tail = tail->previous;
        delete tail->next;
    }
    delete tail;
}
//Inserts to the beggining of our list if the size is 0 then we have to set our head and tail equal to this.
void DLL::insertBeg(int data) {
    node* toInsert = new node(data);
    if (size == 0){
        head = toInsert;
        tail = toInsert;
        size++;
        return;
    }
        toInsert->next = head;
        head->previous = toInsert;
        head = toInsert;
        size++;
}

void DLL::removeBeg() {
    if (size == 0){return;}
    if (size == 1){delete head; return;}
    node* toDelete = head;
    head = head->next;
    head->previous = nullptr;
    delete toDelete;
    size--;
}

void DLL::insertEnd(int data) {
    node* toInsert = new node(data);
    if (size == 0){
        head = toInsert;
        tail = toInsert;
        size++;
        return;
    }

    tail->next=toInsert;
    toInsert->previous=tail;
    tail = toInsert;
    size++;
}

void DLL::removeEnd() {
    node* toDelete = tail;
    tail->previous->next=nullptr;
    tail = tail->previous;
    delete toDelete;
    size--;
}

void DLL::printWhile() {
    std::cout << "Size: " << size << " | " << "Head: " << head->data << " | " << "Tail: " << tail->data << " |   ";
    node* current = head;
    while(current!= nullptr){
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DLL::printRec(node* current) {
    if(current == nullptr){
        std::cout << std::endl;
        return;
    }
    std::cout << current->data << " ";
    printRec(current->next);
}

void DLL::printFor() {
    node* current = head;
    for(int i = 0; i < size; ++i) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DLL::insertSortWhile(int data) {
    node* toInsert = new node(data);
    node* current = head;
    // If our head is greater than our data in a sorted list this means that our new node needs to be inserted before our head
    if (head->data > data){
        head->previous = toInsert;
        toInsert->next = head;
        head = toInsert;
        size++;
        return;
    }
    // If our tail is less than our data in a sorted list this means that our new node needs to be inserted at the end
    if(tail->data < data){
        tail->next = toInsert;
        toInsert->previous = tail;
        tail = toInsert;
        size++;
        return;
    }
    // Otherwise we find the node that our data is less than or equal to and insert link it to the previous node
    while (current->next->data < data){
        current = current->next;
    }
    toInsert->next = current->next;
    current->next = toInsert;
    toInsert->previous = current;
    size++;
}

void DLL::insertSortRec(int data, node* current) {
    //Base case 1 we find the node that our data is less than or equal to and insert link it to the previous node
        if (current->next->data >= data){
            node* toInsert = new node(data);
            toInsert->next = current->next;
            current->next = toInsert;
            toInsert->previous = current;
            size++;
            return;
        }
    // Base case 2 Our head is greater than our data in a sorted list this means that our new node needs to be inserted before our head
    if (head->data > data){
        node* toInsert = new node(data);
        head->previous = toInsert;
        toInsert->next = head;
        head = toInsert;
        size++;
        return;
    }
    // Base Case 3 our tail is less than our data in a sorted list this means that our new node needs to be inserted at the end
    if(tail->data < data){
        node* toInsert = new node(data);
        tail->next = toInsert;
        toInsert->previous = tail;
        tail = toInsert;
        size++;
        return;
    }
    insertSortRec(data, current->next);
}

void DLL::insertSortFor(int data) {
    node* toInsert = new node(data);
    node* current = head;
    // If our head is greater than our data in a sorted list this means that our new node needs to be inserted before our head
    if (head->data > data){
        head->previous = toInsert;
        toInsert->next = head;
        head = toInsert;
        size++;
        return;
    }
    // If our tail is less than our data in a sorted list this means that our new node needs to be inserted at the end
    if(tail->data < data){
        tail->next = toInsert;
        toInsert->previous = tail;
        tail = toInsert;
        size++;
        return;
    }
        for(int i = 0; i < size; i++){
            if (current->next->data >= data){
                break;
            }
            current=current->next;
        }
    toInsert->next = current->next;
    current->next = toInsert;
    toInsert->previous = current;
    size++;

}

void DLL::deleteSortWhile(int data) {
    if(head->data == data){
        head = head->next;
        delete head->previous;
        size--;
        return;
    }
    if (tail->data == data){
        tail = tail->previous;
        delete tail->next;
        size--;
        return;
    }
    node* current = head;
    int doesNotExist = 0;
    while (current->data != data){
        if (doesNotExist>size){
            std::cout << "This number is not in our array." << std::endl;
            return;
        }
        current=current->next;
        doesNotExist++;
    }
    current->previous->next = current->next;
    current->next->previous = current->previous;
    size--;
}

void DLL::deleteSortRec(int data, node* current) {
    if (current->data == data){
        current->previous->next = current->next;
        current->next->previous = current->previous;
        size--;
        return;
    }
    if(head->data == data){
        head = head->next;
        delete head->previous;
        size--;
        return;
    }
    if (tail->data == data){
        tail = tail->previous;
        delete tail->next;
        size--;
        return;
    }
    deleteSortRec(data, current->next);
}

void DLL::deleteSortFor(int data) {
    if(head->data == data){
        head = head->next;
        delete head->previous;
        size--;
        return;
    }
    if (tail->data == data){
        tail = tail->previous;
        delete tail->next;
        size--;
        return;
    }
    node* current = head;
    for(int i = 0; i < size; i++){
        if (current->data == data){
            break;
        }
        current=current->next;
    }
    current->previous->next=current->next;
    current->next->previous = current->previous;
    size--;
}
