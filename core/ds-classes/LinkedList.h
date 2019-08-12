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
            head->next=NULL;
            tail=NULL;
        }

        void addNode(Node *node);
        // setters
        void setNode_int(int pos, int value);
        void setNode_double(int pos, double value);
        void setNode_char(int pos, char value);
        // gets head and tail, and list size;
        Node* getHead();
        Node* getTail();
        int list_size();
        // creation value methods;
        void createNode_int(int value);
        void createNode_double(double value);
        void createNode_float(float value);
        void createNode_char(char value);
        void createNode_short(short value);
        void createNode_long(long value);
        void createNode_uint8_t(uint8_t value);
        void createNode_uint16_t(uint16_t value);
        void createNode_uint32_t(uint32_t value);
        void setNode(Node *node);
          
};
#endif