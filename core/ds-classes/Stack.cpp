#include "Stack.h"

template<class S>
void Stack<S>::push(S const& item) {
    stack.add(item);
}

template<class S>
S Stack<S>::pop() {
    return stack[stack.size() - 1];

}

template <class S>
S Stack<S>::top() {
    return stack[stack.size() - 1];
}

template<class S>
void Stack<S>::clear() {
    stack.clear();
}
 
template<class S>
bool Stack<S>::isEmpty() {
    return stack.size() == 0;
} 
TMP_TYPE(Stack, Queue<Event*>*);
TMP_TYPE(Stack, Event);
TMP_TYPE(Stack, Event*);
TMP_TYPE(Stack, double);
TMP_TYPE(Stack, float);
TMP_TYPE(Stack, int);
TMP_TYPE(Stack, char);
TMP_TYPE(Stack, short);
TMP_TYPE(Stack, long);
TMP_TYPE(Stack, String);