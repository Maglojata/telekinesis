#ifndef _N_D_
#define _N_D_
#include <iostream>
	
	void* my_oper_new(size_t length){
		void* p = std::malloc(length);
			if (!p) {
				throw std::bad_alloc();
			}
		return p;
	} 
	
        void my_oper_delete(void* p) {
		if (p) {
			std::free(p);
		}
	}
	
        // new, delete operators

        template <typename T>
        T* my_new(T){
		void* p = ::my_oper_new(sizeof(T));
		T* pp = static_cast<T*>(p);
		*pp = T();
		return pp;
	}

        template <typename T>
        void my_delete(T* p) {
		if (p) {
			T::~T(p);
			::my_oper_delete(p);
		}
	}


        //new[], delete[]

        template <typename T>
        T* my_new_arr(size_t length) {
		void* p = ::my_oper_new(length * sizeof(T));
		T* pp = static_cast<T*>(p);
			for (size_t i = 0; i < length; ++i) {
				new (pp + i)T;
			}
		return pp;
	}

        template <typename T>
	void my_delete_arr(T* p, size_t length){
		if (p) {
			for (size_t i = length - 1 - i; i != -1; --i){
				T::~T(p + i);
			}
			::my_oper_delete(p);
		}
	}		
		
#endif
	
