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
        vector(size_type length);
        vector(size_type length, const_reference val);
        vector(const vector& rhv);
        vector(vector&& rhv);
        vector(std::initializer_list<value_type> init);
        ~vector();

    public:
        const vector& operator=(const vector& rhv);
        const vector& operator=(vector&& rhv);

    private:
        void reserve(size_type count);

    public:
        void clear();
        void print();
        void resize(size_type size, const_reference val);
        void push_back(const_reference val);
        void pop_back();
        void insert(size_type index, const_reference val);
        void erase(size_type index);

    public:
        reference at(size_type index);
        reference front();
        reference back();

    public:
        size_type size();
        size_type capacity();
        bool empty();

    public:
        reference operator[](size_type index);

};
    namespace std {
	    template <typename T>
    	ostream& operator <<(ostream& out, const vector<T>& ob);
    }


#include "vector.hpp"
#endif
