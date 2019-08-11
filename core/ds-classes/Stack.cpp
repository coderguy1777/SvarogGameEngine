#include "Stack.h"

template<class S>
void Stack<S>::push(S const& item) {
    Stack.add(item);
}

template<class S>
S Stack<S>::pop() {
    return Stack.remove(topPiece);
}

template <class S>
S Stack<S>::top() {
    return Stack.get(topPiece);
}

template<class S>
void Stack<S>::clear() {
    Stack.clear();
}

template<class S>
bool Stack<S>::isEmpty() {
    return (Stack.size() == 0) ? true : false;
}