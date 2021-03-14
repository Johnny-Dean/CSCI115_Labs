//
// Created by Johnny on 3/13/2021.
//

#include <iostream>
#include "HashTable.h"
using std::cout;

HashTable::HashTable() {
    Node* Fill = new Node;
    for (int i = 0; i < 50; i++){
        table[i] = Fill;
    }
}

void HashTable::insert(int sum) {
    Node *toInsert = new Node;
    toInsert->sum = sum;
    int hashIndex = hash(sum);
    // if matching sum, increase the count
    if (table[hashIndex]->sum == toInsert->sum){
        table[hashIndex]->count++;
        return;
    }
    // empty at this index
    else if (table[hashIndex]->sum == -1){
        table[hashIndex] = toInsert;
    }
    else{
        Node* current = table[hashIndex];
        if (current->next == nullptr){
            current->next = toInsert;
        }
        // navigate to the node before insertion or counter increase
            while (current->next !=nullptr){
                if(current->next->sum == sum){
                    break;
                }
                current = current->next;
            }
            // if end of linked list
            if(current->next == nullptr){
                current->next = toInsert;
            }
                // found matching sum in linked list
            else if (current->next->sum == toInsert->sum){
                current->next->count++;
            }
    }
}

int HashTable::find(int sum) {
    int findIndex = hash(sum);
    // doesn't exist
    if(table[findIndex]->sum == -1){
        return 0;
    }
    // if the node at hash index is filled
    if (table[findIndex]->sum != -1){
        Node* current = table[findIndex];
        // the first node at index is equal to our sum
        if (current->sum == sum){
            return current->count;
        }
        // however, if it is not at that index but the index has a linked list we check
        else if(current->next != nullptr){
            while (current != nullptr){
                if (current->sum==sum){
                    return current->count;
                }
                current=current->next;
            }
            return 0;
        }
        return 0;
    }
}

void HashTable::display() {
    for(int i = 0; i < 50; i++){
        if (table[i]->sum == -1){
            cout << "Nothing at Index: " << i << std::endl;
            continue;
        }
        cout << "At Index: " << i << " ";
        cout << "Sum: " << table[i]->sum << " Count: " << table[i]->count << std::endl;
        if (table[i]->next != nullptr){
            Node* current = table[i]->next;
            int node = 1;
            while(current->next != nullptr){
                cout << "   Linked List At Index: " << i << " Node: " << node << " Sum: " << current->sum << " Count: " << current->count << std::endl;
                node++;
                current=current->next;
            }
        }
    }
}

int HashTable::hash(int key) {
    return key % 50; // hash function given by ceccoti
}

