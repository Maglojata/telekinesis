#include "../header/vector.h"
#include <iostream>
#include <memory>


int main() {
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "First element: " << vec.front() << std::endl;
    std::cout << "Last element: " << vec.back() << std::endl;

    vec.insert(vec.cbegin(), 5, 5);  
    vec.insert(vec.begin(), 6);
    vec.insert(vec.begin() + 4, {22, 33, 44, 55});
    vec.erase(vec.begin(), vec.end() - 5);
    vec.erase(vec.begin() + 1);


    for (int value : vec) {
        std::cout << value << " ";
    }

    std::cout << std::endl;
    return 0;
}