#include <iostream>
#include "../header/queue.tpp" 

int main() {

    g3::queue<int> intQueue {};

    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);

    std::cout << "Front of the queue: " << intQueue.front() << std::endl;
    std::cout << "Back of the queue: " << intQueue.back() << std::endl;

    intQueue.pop();

    std::cout << "Is the queue empty? " << (intQueue.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Size of the queue: " << intQueue.size() << std::endl;

    g3::queue<int> anotherQueue = {1, 2, 3, 4, 5};

   if (intQueue == anotherQueue) {
       std::cout << "The queues are equal in size." << std::endl;
   } else {
       std::cout << "The queues are not equal in size." << std::endl;
   }
    
return 0;
}
