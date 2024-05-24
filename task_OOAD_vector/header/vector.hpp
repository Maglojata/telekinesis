#ifndef __VECTOR__TPP__
#define __VECTOR__TPP__

#include <iostream>
#include <memory>
#include "vector.h"

template <typename T, typename Allocator>
vector<T, Allocator>::vector()
    : size_{0}
    , capacity_{0}
    , arr_{nullptr}
{}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const vector &rhv)
    : size_{rhv.size_}
    , capacity_{rhv.capacity_}
    , arr_{alloc.allocate(rhv.capacity_)}
{
    for (size_t i = 0; i < rhv.size_; ++i)
    {
        alloc.construct(arr_ + i, rhv.arr_[i]);
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(vector &&rhv)
{
    size_ = rhv.size_;
    capacity_ = rhv.capacity_;
    arr_ = rhv.arr_;
    rhv.size_ = 0;
    rhv.capacity_ = 0;
    rhv.arr_ = nullptr;
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(std::initializer_list<value_type> init)
    : vector()
{
    for (const value_type &i : init)
    {
        push_back(i);
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(size_type size, const_reference val)
    : size_{size}
    , capacity_(size)
    , arr_{alloc.allocate(size)}
{
    for (size_type i = 0; i < size_; ++i)
    {
        alloc.construct(arr_[i], val);
    }
}

template <typename T, typename Allocator>
template <typename InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last)
    : size_(std::distance(first, last))
    , capacity_(std::distance(first, last))
    , arr_(alloc.allocate(capacity_)) 
{
    size_type i = 0;
    try {
        for (; first != last; ++first, ++i) {
            alloc.construct(arr_ + i, *first);
        }
    } catch(...) {
        for (size_t j = 0; j < i; ++j) {
            alloc.destroy(arr_ + j);
        }
        alloc.deallocate(arr_, capacity_);
        throw;
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::~vector()
{
    clear();
}

template <typename T, typename Allocator>
const vector<T, Allocator> &
vector<T, Allocator>::operator=(const vector &rhv)
{
    if (this != &rhv)
    {
        clear();
        size_ = rhv.size_;
        capacity_ = rhv.capacity_;
        arr_ = alloc.allocate(rhv.capacity_);
        for (size_type i = 0; i < rhv.size_; ++i)
        {
            alloc.construct(arr_[i], rhv.arr_[i]);
        }
    }
    return *this;
}

template <typename T, typename Allocator>
const vector<T, Allocator> &
vector<T, Allocator>::operator=(vector &&rhv)
{
    if (this != &rhv)
    {
        clear();
        size_ = std::move(rhv.size_);
        capacity_ = std::move(rhv.capacity_);
        arr_ = rhv.arr_;
        rhv.arr_ = nullptr;
    }
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type
vector<T, Allocator>::get_allocator()
{
    return alloc;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::at(size_type pos)
{
    if (pos < size_)
    {
        return size_[pos];
    }
    throw 1;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::at(size_type pos) const
{
    if (pos < size_)
    {
        return size_[pos];
    }
    throw 1;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::operator[](size_type pos)
{
    return size_[pos];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::operator[](size_type pos) const
{
    return size_[pos];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::front()
{
    if (!empty())
    {
        throw 1;
    }
    return arr_[0];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::front() const
{
    if (!empty())
    {
        throw 1;
    }
    return arr_[0];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::back()
{
    if (!empty())
    {
        throw 1;
    }
    return arr_[size_ - 1];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::back() const
{
    if (!empty())
    {
        throw 1;
    }
    return arr_[size_ - 1];
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::begin()
{
    return iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::begin() const
{
    return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::cbegin() const
{
    return const_iterator(arr_);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::end()
{
    return iterator(arr_ + 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::end() const
{
    return const_iterator(arr_ + 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::cend() const
{
    return const_iterator(arr_ + 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::rbegin()
{
    return iterator(arr_ + size_ - 1);
}
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::rbegin() const
{
    return const_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::crbegin() const
{
    return const_iterator(arr_ + size_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::rend()
{
    return iterator(arr_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::rend() const
{
    return const_iterator(arr_ - 1);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::crend() const
{
    return const_iterator(arr_ - 1);
}

template <typename T, typename Allocator>
bool vector<T, Allocator>::empty() const
{
    return !size_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::size() const
{
    return size_;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::capacity() const
{
    return capacity_;
}


template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type new_cap)
{
    if (new_cap > capacity_) {
        pointer new_memory = alloc.allocate(new_cap);
        for (size_t i = 0; i < size_; ++i) {
            alloc.construct(new_memory + i, arr_[i]);
            alloc.destroy(arr_ + i);
        }
        alloc.deallocate(arr_, capacity_);
        arr_ = new_memory;
        capacity_ = new_cap;
    }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::clear() noexcept
{
    for (size_t i = 0; i < size_; ++i){
        alloc.destroy(arr_ + i);
    }
    alloc.deallocate(arr_, capacity_);
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(const_iterator pos, const_reference val) {
    size_type index = pos - begin();
    emplace(begin() + index, val);
    return begin() + index;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) {
    size_type index = pos - begin();
    reserve(size() + count);
    iterator instPos = begin() + index;
    for (size_t i = 0; i < count; ++i){
        instPos = emplace(instPos, val);
    }
    return instPos;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) {
    size_type index = pos - begin();
    reserve(size() + init.size());
    iterator instPos = begin() + index;
    for (const_reference val : init){
        instPos = emplace(instPos, val);
    }
    return instPos;
}

template <typename T, typename Allocator>
template <typename InputIt>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last){
    size_type index = pos - begin();
    reserve(size() + std::distance(first, last));
    iterator instPos = begin() + index;
    while (first != last) {
        instPos = emplace(instPos, *first);
        ++first;
    }
    return instPos;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(const_iterator pos) {
    iterator erasePos = begin() + (pos - begin());
    for (iterator it = erasePos; it + 1 != end(); ++it) {
        *it = *(it + 1);
    }
    --size_;
    return erasePos;
}


template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::erase(const_iterator first, const_iterator last) {
    iterator eraseStart = begin() + (first - begin());
    iterator eraseEnd = begin() + (last - begin());
    iterator newEnd = eraseStart;
    while (eraseEnd != end()) {
        *newEnd = *eraseEnd;
        ++newEnd;
        ++eraseEnd;
    }
    size_ -= eraseEnd - eraseStart;
    return newEnd;
}

template <typename T, typename Allocator>
void
vector<T, Allocator>::push_back(const_reference val) {
    resize(capacity_ * 2);
    arr_[size_++] = val;
}

template <typename T, typename Allocator>
void
vector<T, Allocator>::pop_back() {
    if (size_ != 0) {
        alloc.destroy(arr_ + size_ - 1);
        --size_;
    }
    throw 1;
}

template <typename T, typename Allocator>
void
vector<T, Allocator>::resize(size_type new_size, const_reference val) {
    if (new_size < size_){
        size_ = new_size;
    } else {
        reserve(capacity_ * 2);
        for (size_t i = size_; i < new_size; ++i) {
            alloc.construct(arr_ + i, val);
        }
        size_ = new_size;
    }
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator==(const vector &other) const {
    return !compare(other);
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator!=(const vector &other) const {
    return !!compare(other);
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator<(const vector &other) const {
    return compare(other) == -1;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator<=(const vector &other) const {
    return compare(other) == -1;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator>(const vector &other) const {
    return compare(other) == 1;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::operator>=(const vector &other) const {
    return compare(other) == 1;
}

template <typename T, typename Allocator>
int
vector<T, Allocator>::compare(const vector &other) const {
    if (size_ < other.size_) {
        return -1;
    }
    if (size_ > other.size_) {
        return 1;
    }

    for (size_t i = 0; i < size_; ++i) {
        if (arr_[i] < other.att_[i]) {
            return -1;
        }
        if (arr_[i] > other.arr_[i]) {
            return 1;
        }
    }
    return 0;
}

///____________________________________________

template <typename T, typename Allocator>
vector<T, Allocator>::const_iterator
::const_iterator(pointer ptr) 
    : ptr{ptr}
{}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator+(size_type n) const {
    return const_iterator(ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator-(size_type n) const {
    return const_iterator(ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator++() {
    ++ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator++(int) {
    const_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator&
vector<T, Allocator>::const_iterator::operator--() {
    --ptr;
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator
vector<T, Allocator>::const_iterator::operator--(int) {
    const_iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_iterator::operator*() const {
    return *ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_pointer
vector<T, Allocator>::const_iterator::operator->() const {
    return ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_iterator::operator[](size_type pos) const {
    return ptr[pos];
}
     
template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator==(const const_iterator &other) const {
    return ptr == other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator!=(const const_iterator &other) const {
    return ptr != other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator<(const const_iterator &other) const {
    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator<=(const const_iterator &other) const {
    return ptr <= other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator>(const const_iterator &other) const {
    return ptr > other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_iterator::operator>=(const const_iterator &other) const {
    return ptr >= other.ptr;
}

////---------------------------------------

template <typename T, typename Allocator>
vector<T, Allocator>::iterator::iterator(pointer ptr) {
    this->ptr = ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator+(size_type n) const {
    return iterator(this->ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator-(size_type n) const {
    return iterator(this->ptr - n);
}   

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator++() {
    ++this->ptr;
    return *this;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator++(int) {
    iterator tmp = *this;
    ++(*this);
    return tmp;
} 
    
template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator&
vector<T, Allocator>::iterator::operator--() {
    --(this->ptr);
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::iterator
vector<T, Allocator>::iterator::operator--(int) {
    iterator tmp = *this;
    --(*this);
    return tmp;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::iterator::operator*() {
    return *this->ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::pointer
vector<T, Allocator>::iterator::operator->() {
    return this->ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::iterator::operator[](size_type pos) const {
    return this->ptr[pos];
}



/// ------------------------------------+++++++++++--
template <typename T, typename Allocator>
vector<T, Allocator>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
    : ptr{ptr}
{}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator+(size_type n) const {
    return const_reverse_iterator(ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator-(size_type n) const {
    return const_reverse_iterator(ptr + n);
}
  
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator++() {
    return --ptr;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator++(int) {
    const_reverse_iterator tmp = *this;
    --(*this);
    return tmp;
} 
    
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator&
vector<T, Allocator>::const_reverse_iterator::operator--() {
    ++(this->ptr);
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator
vector<T, Allocator>::const_reverse_iterator::operator--(int) {
    const_reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}
    
template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_reverse_iterator::operator*() const {
    return *ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_pointer
vector<T, Allocator>::const_reverse_iterator::operator->() const{
    return ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::const_reference
vector<T, Allocator>::const_reverse_iterator::operator[](size_type pos) const {
    return ptr[pos];
}


template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator==(const const_reverse_iterator &other) const {
    return ptr == other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator!=(const const_reverse_iterator &other) const {
    return ptr != other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator<(const const_reverse_iterator &other) const {
    return ptr < other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator<=(const const_reverse_iterator &other) const {
    return ptr <= other.ptr;
}

template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator>(const const_reverse_iterator &other) const {
    return ptr > other.ptr;
}
    
template <typename T, typename Allocator>
bool
vector<T, Allocator>::const_reverse_iterator::operator>=(const const_reverse_iterator &other) const {
    return ptr >= other.ptr;
}
 

///------------------------------

template <typename T, typename Allocator>
vector<T, Allocator>::reverse_iterator::reverse_iterator(pointer ptr) {
    this->ptr(ptr);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator+(size_type n) const {
    return reverse_iterator(this->ptr - n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator-(size_type n) const {
    return reverse_iterator(this->ptr + n);
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator++() {
    --(this->ptr);
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator++(int) {
    reverse_iterator tmp = *this;
    --(*this);
    return tmp;
} 
    
template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator&
vector<T, Allocator>::reverse_iterator::operator--() {
    ++(this->ptr);
    return *this;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator
vector<T, Allocator>::reverse_iterator::operator--(int) {
    reverse_iterator tmp = *this;
    ++(*this);
    return tmp;
}

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::reverse_iterator::operator*() {
    return *this->ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::pointer
vector<T, Allocator>::reverse_iterator::operator->() {
    return this->ptr;
} 

template <typename T, typename Allocator>
typename vector<T, Allocator>::reference
vector<T, Allocator>::reverse_iterator::operator[](size_type pos) const {
    return this->ptr[pos];
}


#endif //__VECTOR__TPP__
