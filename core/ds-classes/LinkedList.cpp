#include "LinkedList.h"
void LinkedList::addNode(Node *node) {
    ASSERT_EQUAL(node->next, NULL);
    if(head==NULL) {
        head=node;
        tail=head;
        node=NULL;
    } else {
        tail->next=node;
        tail=node;
    }
}

int LinkedList::list_size() {
    Node *p;
    p=head;
    int size = 0;
    while(p!=NULL) {
        p=p->next;
        size++;
    }
    return size;
}

void LinkedList::createNode_int(int value) {
    Node *temp = new Node;
    temp->data_int = value;
    addNode(temp);
}

void LinkedList::createNode_double(double value) {
    Node *temp = new Node;
    temp->data_double = value;
    addNode(temp);
}

void LinkedList::createNode_float(float value) {
    Node *temp = new Node;
    temp->data_float = value;
    addNode(temp);
}

void LinkedList::createNode_char(char value) {
    Node *temp = new Node;
    temp->data_char = value;
    addNode(temp);
}

void LinkedList::createNode_short(short value) {
    Node *temp = new Node;
    temp->data_short = value;
    addNode(temp);
}

void LinkedList::createNode_long(long value) {
    Node *temp = new Node;
    temp->data_long = value;
    addNode(temp);
}

void LinkedList::createNode_uint8_t(uint8_t value) {
    Node *temp = new Node;
    temp->data_uint8 = value;
    addNode(temp);
}

void LinkedList::createNode_uint16_t(uint16_t value) {
    Node *temp = new Node;
    temp->data_uint16 = value;
    addNode(temp);
}

void LinkedList::createNode_uint32_t(uint32_t value) {
    Node *temp = new Node;
    temp->data_uint32 = value;
    addNode(temp);
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail;
}

void LinkedList::setNode_int(int pos, int value) {
    Node *curr = new Node;
    Node *prev = new Node;
    Node *temp = new Node;
    curr=head;
    int posCurr = 0;
    while(curr != NULL && posCurr <= pos) {
        prev=curr;
        curr=curr->next;
        posCurr++;
        if(posCurr == pos) {
            break;
        }
    }
    temp->data_int = value;
    prev->next = temp;
    temp->next = curr;
}

void LinkedList::setNode_double(int pos, double value) {
    Node *curr = new Node;
    Node *prev = new Node;
    Node *temp = new Node;
    curr=head;
    int counter = 0;
    while(curr!=NULL) {
        prev=curr;
        curr=curr->next;
        counter++;
        if(counter==pos) {
            break;
        }
    }
    temp->data_double = value;
    prev->next = temp;
    temp->next = curr;
}

void LinkedList::setNode_char(int pos, char value) {
    Node *curr = new Node;
    Node *prev = new Node;
    Node *temp = new Node;
    curr=head;
    int counter = 0;
    while(curr != NULL) {
        prev = curr;
        curr=curr->next;
        counter++;
        if(counter == pos) {
            break;
        }
    }
    temp->data_char=value;
    prev->next = temp;
    temp->next = curr;
}