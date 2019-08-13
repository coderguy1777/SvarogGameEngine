#include "Stack.h"

template<class S>
void Stack<S>::push(S const& item) {
    stack.add(item);
}

template<class S>
S Stack<S>::pop() {
    S item = stack.remove(topPiece);
    return item;
}

template <class S>
S Stack<S>::top() {
    S item =  stack.get(topPiece);
    return item;
}

template<class S>
void Stack<S>::clear() {
    stack.clear();
}

template<class S>
bool Stack<S>::isEmpty() {
    return stack.size() == 0;
}