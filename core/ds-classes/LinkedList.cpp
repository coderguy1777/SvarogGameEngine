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

Node* LinkedList::createNode() {

}