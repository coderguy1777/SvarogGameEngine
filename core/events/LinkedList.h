#pragma once
#ifdef LINKEDLIST_H
#define LINKEDLIST_H
#endif
#include "core/ArrayList.h"
struct Node {
    int data;
    Node *next;
    void * operator new(size_t size) {
        Node * item = new Node;
    }
};
template<class T>
class LinkedList {
    private:
        ArrayList<T>lst;
        Node curr;
        Node prev;
        Node tail;
        Node temp;
        Node head;
    public: 
        Node traverseList();
        void addNode(T const& item);
        void createNode(T const& item);
        void printList();
        bool isEmpty();
        void removeItem(int index);
};

