#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ArrayList.h"
#include "macrodefs.h"
#include "Node.h"
FORWARD_DEC(LinkedList);
class LinkedList {
    private:
        Node* head; 
        Node* tail;
    public:
        LinkedList() {
            head=NULL;
            tail=NULL;
        }

        void addNode(Node *node);
        int list_size();
        Node* createNode();
};
#endif