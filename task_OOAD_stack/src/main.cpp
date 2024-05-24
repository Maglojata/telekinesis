#include <iostream>
#include <deque>
#include "../header/stack.h" 


int main() {
    g3::stack<int, std::deque<int>> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top element: " << intStack.top() << std::endl;

    intStack.pop();

    std::cout << "Top element after pop: " << intStack.top() << std::endl;

    if (intStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    std::cout << "Size of the stack: " << intStack.size() << std::endl;

    g3::stack<int, std::deque<int>> anotherStack;

    anotherStack.push(5);
    anotherStack.push(15);
    anotherStack.push(25);

    if (intStack == anotherStack) {
        std::cout << "The two stacks have the same size." << std::endl;
    } else {
        std::cout << "The two stacks have different sizes." << std::endl;
    }

    return 0;
}

