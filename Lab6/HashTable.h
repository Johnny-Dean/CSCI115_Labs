// Created by xander on 2021-02-25
// This is a header file for a hash table. Your job is to implement the functions declared in a separate HashTable.cpp
// When inserting a new elements use separate chaining to deal with collisions.
#ifndef LAB6_HASHTABLE
#define LAB6_HASHTABLE

//Node struct used to forms lists (chains) inside the hash table
struct Node{
    int sum = -1;
    int count = 1;
    Node * next = nullptr;
};
//The hash table class allows quick insertion/access of elements
class HashTable {
public:
    Node* table[50];                    //array of 50 Node pointers
    HashTable();                        //creates an empty hash table of size M
    void insert(int sum);               //inserts sum to the hash table, if sum already exists increases count
    //inert uses separate chaining to deal with collisions
    int find(int sum);                  //finds the count of a sum, if the sum doesn't exist returns 0
    void display();                     //displays the sums in the array and their count
    int hash(int key);                  //uses the hash function % M to find an index for the given key
};

#endif //LAB6_HASHTABLE
