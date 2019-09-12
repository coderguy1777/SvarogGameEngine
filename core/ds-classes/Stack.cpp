#include "Stack.h"

template<class S>
void Stack<S>::push(S const& item) {
    stack.push(item);
}

template<class S>
void Stack<S>::pop() {
    stack.pop();
}

template <class S>
S Stack<S>::top() {
    return stack.top();
}

template<class S>
void Stack<S>::clear() {
    for(unsigned int i = 0; i < stack.size(); i++) {
        stack.pop();
    }
}
 
template<class S>
bool Stack<S>::isEmpty() {
    return (stack.size() == 0) ? true : false;
} 

template<class S>
int Stack<S>::size() const {
    return stack.size();
}

TMP_TYPE(Stack, Queue<Event*>*);
TMP_TYPE(Stack, Event);
TMP_TYPE(Stack, KeyEvent);
TMP_TYPE(Stack, Event*);
TMP_TYPE(Stack, double);
TMP_TYPE(Stack, float);
TMP_TYPE(Stack, int);
TMP_TYPE(Stack, char);
TMP_TYPE(Stack, short);
TMP_TYPE(Stack, long);
TMP_TYPE(Stack, String);