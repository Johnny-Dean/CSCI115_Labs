//
// Created by Johnny on 3/7/2021.
//

#ifndef LAB_5_DOUBLELINKEDLISTS_H
#define LAB_5_DOUBLELINKEDLISTS_H
struct node{
    node* next;
    node* previous;
    int data;
    node(int data);
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
    void printRec();
    void printFor();
    void insertSortWhile();
    void insertSortRec();
    void insertSortFor();
    void deleteSortWhile();
    void deleteSortRec();
    void deleteSortFor();
};

#endif //LAB_5_DOUBLELINKEDLISTS_H
