#include "../header/vector.h"
#include <iostream>

int main() {
	vector<int> v;
	vector<int> v1(2, 6);
	vector<int> v2(v1);
	// vector<int> v2(v1);
	vector<int> v3{1, 2, 3, 4, 5, 6};

	// v2.print();
	std::cout << std::endl;
	v1.print();
	v3.print();
}