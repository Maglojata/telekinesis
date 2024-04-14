#include <iostream>
#include "../header/queue.h"

int main() {
queue<int>  ob;
	queue<int> ob2 {1, 2, 3, 4, 5};
	queue<int> ob3 = ob2;
	queue<int> ob4 = std::move(ob3);
	ob.push(19);
	ob2.pop();
	ob2.front();
	std::cout << ob2.size() << std::endl;
	ob.swap(ob2);
	std::cout << ob.empty() << std::endl;
	std::cout << "ok" << std::endl;
	
	bool i = ob2 == ob4;
	std::cout << i << std::endl;

	if(ob2 != ob) {
		std::cout << "!=" << std::endl;
	} else {
		std::cout << "!=" << std::endl;
	}
	if(ob2 <= ob) {
		std::cout << "<=" << std::endl;
	} else {
		std::cout << "<=" << std::endl;
	}
	if(ob2 < ob) {
		std::cout << "<" << std::endl;
	} else {
		std::cout << "<" << std::endl;
	}
	if(ob2 >= ob) {
		std::cout << ">=" << std::endl;
	} else {
		std::cout << ">=" << std::endl;
	}
	if(ob2 > ob) {
		std::cout << ">" << std::endl;
	} else {
		std::cout << ">" << std::endl;
	}	

}

