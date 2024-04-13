#include "../header/stack1.h"
#include <iostream>

int main()
{ 
	stack<int, std::vector<int>> ob{1, 2, 3};
	stack<int> ob1(ob);

	stack<int> ob2 = std::move(ob1);

	stack<int> ob4{9, 7, 8, 9};

	bool i = ob1 > ob2;
	std::cout << i;
}
