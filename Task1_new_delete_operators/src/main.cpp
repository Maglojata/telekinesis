#include <iostream>
#include "../header/new_delete.h"

int main() {

	int *pp = my_new_arr<int>(5);
    	for (size_t i = 0; i < 5; ++i){
        	std::cin >>pp[i];
    	}
   
	for (size_t i = 0; i < 5; ++i) {
		std::cout << pp[i];
	}
	
	return 0;
}

	
