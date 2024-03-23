#ifndef __V__R__
#define __V__R__
#include <iostream>

template <typename T>
class vector {
	private:
		size_t m_size;
		size_t m_capacity;
		T* m_arr;
	
	public: 
		using value_type = T;
		using size_type = size_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;

	public:
		vector();
  		vector(size_type);
        	vector(size_type, const_reference);
		vector(const vector&);
		vector(vector&&);
        	vector(std::initializer_list<value_type>);
		~vector();

	public:
		const vector& operator=(const vector&);
		const vector& operator=(vector&&);		
	private:
		void recap(size_type);
		
	public:
		void clear();
		void print();
		void resize(size_type, const_reference);
		void push_back(const_reference);
		void pop_back();
		void insert(size_type, const_reference);
		void erase(size_type index);
	
	public:
		reference at(size_type);
		reference front();
		reference back();

	public:
		size_type size();
		size_type capacity();
                bool empty();
             
};


#include "vector.hpp"

#endif
