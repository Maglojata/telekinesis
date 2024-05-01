#ifndef __ALLOC_
#define __ALLOC_

#include "alloc.h"

template <typename T>
typename Allocator<T>::pointer 
Allocator<T>::allocate(size_type count){
	if (!flag) {
		return static_cast<pointer(static_cast<void*>*(storage));	
	} else {
		return static_cast<pointer>(static_cast<void*>(storage + 1500));
	}
	flag = !flag;
}

template <typename T>
void 
Allocator<T>::deallocate(pointer* ptr, size_type type) {};
	
template <typename Args ... args>		
void construct(pointer* ptr, Args... args) {
	std::construct_at(pointer ptr, std::forward<Args>(args)...);
}

void distroy(pointer ptr) {
	std::distroy_at(ptr);
}	


#endif

