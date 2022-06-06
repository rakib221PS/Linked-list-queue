#ifndef STACK_H
#define STACK_H
class Stack {
    int mem[100];
    int elements;

public:
    Stack();
    void push(int x);
    int top();
    void pop();
};
#endif