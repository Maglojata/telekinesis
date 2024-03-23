#ifndef _NEW_DELETE_
#define _NEW_DELETE_

#include <iostream>
	
	void* my_oper_new(size_t);
	void my_oper_delete(void*);
	
	// new, delete operators
	
	template <typename T>
	T* my_new(T);	

	template <typename T>
	void my_delete(T*);


	//new[], delete[]
	
	template <typename T>
	T* my_new_arr(size_t);

	template <typename T>
	void my_delete_arr(T*, size_t);
	


#include "new_delete.tpp"
#endif
