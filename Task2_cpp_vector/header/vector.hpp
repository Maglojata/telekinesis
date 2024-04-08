#ifndef __V_C_R__
#define __V_C_R__
#include "vector.h"
#include <iostream>

    template <typename T>
    vector<T>::vector(size_type length, const_reference val)
        : m_size{length}
        , m_capacity{length}
        , m_arr{nullptr}
    {
        if (length == 0){
            return;
        }
        m_arr = new value_type[m_capacity];
        for (size_t i = 0; i < length; ++i){
            this -> m_arr[i] = val;
        }
    }

    template <typename T>
    vector<T>::vector(size_type length)
        : vector(length, value_type{})
    {}

    template <typename T>
    vector<T>::vector()
        : vector(0, value_type{})
    {}

    template <typename T>
    vector<T>::vector(const vector& rhv)
        : m_size{rhv.m_size}
        , m_capacity{rhv.m_capacity}
        , m_arr(new value_type[rhv.m_capacity])
        {
            for (size_t i = 0; i < m_size; ++i){
                m_arr[i] = rhv.m_arr[i];
            }
        }

    template <typename T>
    vector<T>::vector(vector&& rhv)
        : m_size{rhv.m_size}
        , m_capacity{rhv.m_capacity}
        , m_arr{rhv.m_arr}
    {
        rhv.m_arr = nullptr;
        rhv.m_size = 0;
        rhv.m_capacity = 0;
    }

    template <typename T>
    vector<T>::vector(std::initializer_list<T> init){
        for (const_reference item : init) {
            push_back(item);
        }
    }

    template <typename T>
    vector<T>::~vector() {
        clear();
    }


    // copy assignment

    template <typename T>
    const vector<T>&
    vector<T>::operator=(const vector& rhv) {
        if (this != &rhv) {
            clear();
            this -> m_size = rhv.m_size;
            this -> m.capacity = rhv.m_capacity;
            this -> m_arr = new value_type[rhv.m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                this -> m_arr[i] = rhv.m_arr[i];
            }
        }
        return *this;
    }


    // move assignment

    template <typename T>
    const vector<T>&
    vector<T>::operator=(vector&& rhv){
        if (this != &rhv) {
            this -> clear();
            m_size = rhv.m_size;
            m_capacity = rhv.m_capacity;
            m_arr = rhv.m_arr;
            rhv.m_arr = nullptr;
            rhv.m_size = 0;
            rhv.m_capacity = 0;
        }
        return *this;
    }

    template <typename T>
    void
    vector<T>::recap(size_type new_capacity) {
            if (this -> m_size == this -> m_capacity) {
                pointer tmp = new value_type[new_capacity];
                for (size_t i = 0; i < m_size; ++i) {
                    tmp[i] = this -> m_arr[i];
                }
                delete [] this -> m_arr;
                this -> m_arr = tmp;
                this -> m_capacity = new_capacity;
            }
        }

    template <typename T>
    void
    vector<T>::clear() {
            if (this -> m_arr != nullptr) {
                delete [] this -> m_arr;
                this -> m_arr = nullptr;
            }
            this -> m_size = 0;
            this -> m_capacity = 0;
        }

    template <typename T>
    void
    vector<T>::resize(size_type size, const_reference val) {
            if (size < this->m_size) {
                this->m_size = size;
            } else {
                recap(size);
                for (size_t i = m_size; i < size; ++i) {
                        this->m_arr[i] = val;
                }
                this->m_size = size;
            }
    }

    template <typename T>
    void
    vector<T>::push_back(const_reference val) {
            recap(this -> m_capacity * 2);
            this -> m_arr[m_size] = val;
            ++this -> m_size;
        }

    template <typename T>
    void
    vector<T>::pop_back(){
            if (this -> m_size != 0) {
               --this -> m_size;
            }
        }

    template <typename T>
    void
    vector<T>::insert(size_type index, const_reference val){
        recap(this -> m_size);
        ++this -> m_size;
        for (size_t i = m_size - 1; i > index; --i){
            this -> m_arr[i] = this -> m_arr[i - 1];
            this -> m_arr[index] = val;
            }
        }

    template <typename T>
    void
    vector<T>::erase(size_type index) {
        for (size_t i = index; i < m_size - 1; ++i) {
        this -> m_arr[i] = this -> m_arr[i + 1];
            }
            --this -> m_size;
        }

    template <typename T>
    void
    vector<T>::print() {
        for (size_t i = 0; i < m_size; ++i){
            std::cout << this -> m_arr[i];
        }
    }

    template <typename T>
    typename vector<T>::reference
    vector<T>::at(size_type index) {
        if (index < this -> m_size) {
            return this -> m_arr[index];
        }
        throw 1;
    }

    template <typename T>
    typename vector<T>::reference
    vector<T>::front() {
        return this -> m_arr[0];
    }

    template <typename T>
    typename vector<T>::reference
    vector<T>::back() {
        return this -> m_arr[this -> m_size - 1];
    }

    template <typename T>
    bool
    vector<T>::empty() {
        return !this -> m_size;
    }

    template <typename T>
    typename vector<T>::size_type
    vector<T>::size(){
        return this -> m_size;
    }

    template <typename T>
    typename vector<T>::size_type
    vector<T>::capacity() {
        return this -> m_capacity;
    }

	template <typename T>
	typename vector<T>::reference
    vector<T>::operator[](size_type index) {
        return m_arr[index];
	}   
        
    template <typename T>
    bool
    operator==(const vector<T>& lhv, const vector<T>& rhv) {
        return lhv == rhv;
    }
    
	namespace std {
    template <typename T>
    	ostream& operator <<(ostream& out, const vector<T>& ob){
        	for (size_t i = 0; i < ob.size(); ++i) {
            	out << ob[i] << ' ';
        	}
    	}
	}	
#endif                                                     
