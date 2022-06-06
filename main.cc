#include <iostream>
#include "stack.h"

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    s.push(4);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
}
