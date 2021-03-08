//
// Created by Johnny on 3/7/2021.
//

#ifndef LAB_5_DOUBLELINKEDLISTS_H
#define LAB_5_DOUBLELINKEDLISTS_H
struct node{
    node* next = nullptr;
    node* previous = nullptr;
    int data;
    node(int data){
        this->data = data;
    };
};
class DLL{
public:
    node* head;
    node* tail;
    int size; // Size for for loop
    DLL();
    ~DLL();
    void insertBeg(int data);
    void removeBeg();
    void insertEnd(int data);
    void removeEnd();
    void printWhile();
    void printRec(node* current);
    void printFor();
    void insertSortWhile(int data);
    void insertSortRec(int data, node* current);
    void insertSortFor(int data);
    void deleteSortWhile(int data);
    void deleteSortRec(int data, node* current);
    void deleteSortFor(int data);
};

#endif //LAB_5_DOUBLELINKEDLISTS_H
