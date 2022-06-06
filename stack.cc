
#include "stack.h"
Stack::Stack():elements(0) {}

void Stack::push(int x) {
    mem[elements] = x;
    elements++;
}

int Stack::top() {
    return mem[elements - 1];
}

void Stack::pop() {
    elements--;
}
