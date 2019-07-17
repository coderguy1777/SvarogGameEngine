#include "LinkedList.h"
template<class T>
Node LinkedList<T>::traverseList() {
    Node p;
    while(p->next != NULL) {
        p = p->next;
    }
    return p;
}

template <class T>
void LinkedList<T>::addNode(T const& item) {
    if(item->data != NULL) {
        Node val;
        val.data = item;
        lst.add(val);
    } else {
        Node val2;
        val2.data = NULL;

    }
}

template <class T>
void LinkedList<T>::createNode(T const& item) {
    Node * val = new Node;
    val->next = NULL;
    val->data = item;
    if(head == NULL) {
        temp = val;
        head = temp;
        tail = temp;
        temp = NULL;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

template <class T>
void LinkedList<T>::printList() {
    Node *temp = new Node;
    temp = head;
    while(temp != null) {
        cout << temp->data << endl;
    }
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return (lst.size() == 0) ? true : false;
}

template<class T>
void LinkedList<T>::removeItem(int index) {
    lst.remove(index);
}