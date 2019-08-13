#include "Stack.h"

template<class S>
void Stack<S>::push(S const& item) {
    stack.add(item);
}

template<class S>
S Stack<S>::pop() {
    return stack.remove(topPiece);

}

template <class S>
S Stack<S>::top() {
    return stack.get(topPiece);
}

template<class S>
void Stack<S>::clear() {
    stack.clear();
}
 
template<class S>
bool Stack<S>::isEmpty() {
    return stack.size() == 0;
} 