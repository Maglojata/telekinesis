#ifndef __QUEUE__TPP__
#define __QUEUE__TPP__

#include <deque>
#include "queue.h"

template <typename T, typename Container>
g3::queue<T, Container>::queue()
    : ob()
{}

template <typename T, typename Container>
g3::queue<T, Container>::queue(const queue& rhv)
	: ob{rhv.ob}
{}
template <typename T, typename Container>
g3::queue<T, Container>::queue(queue&& rhv)
	:ob{std::move(rhv.ob)}
{
	rhv.ob.clear();
}

template <typename T, typename Container>
g3::queue<T, Container>::queue(std::initializer_list<value_type> init)
{
	for (auto &i : init) {
		ob.push_back(i);
	}
}
		
//iterator________________________________
//template <typename InputIt>
//g3::queue(InputIt first, InputIt last);


template <typename T, typename Container>
g3::queue<T, Container>::~queue()
{}

template <typename T, typename Container>
const g3::queue<T, Container>& 
g3::queue<T, Container>::operator=(const queue& rhv)
{
	if (this != &rhv) {
		ob.clear();
		ob = rhv.ob;
	}
	return *this;
}

template <typename T, typename Container>
const g3::queue<T, Container>&
g3::queue<T, Container>::operator=(queue&& rhv)
{
	if (this != &rhv) {
		ob.clear();
		ob = std::move(rhv.ob);
	}
	return *this;
}

template <typename T, typename Container>
typename g3::queue<T, Container>::reference 
g3::queue<T, Container>::front()
{
	return ob.front();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::const_reference
g3::queue<T, Container>::front() const    
{
	return ob.front();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::reference
g3::queue<T, Container>::back()
{
	return ob.back();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::const_reference
g3::queue<T, Container>::back() const
{
	return ob.back();
}
template <typename T, typename Container>
bool
g3::queue<T, Container>::empty() const
{
	return ob.empty();
}

template <typename T, typename Container>
typename g3::queue<T, Container>::size_type
g3::queue<T, Container>::size() const
{
	return ob.size();
}

template <typename T, typename Container>
void
g3::queue<T, Container>::push(const_reference val)
{
	ob.push_back(val);
}

template <typename T, typename Container>
void
g3::queue<T, Container>::pop()
{
    ob.pop_front();
}

template <typename T, typename Container>
bool
g3::queue<T, Container>::operator==(const queue& other)
{
	return (ob.size() == other.size());		
}

template <typename T, typename Container>
bool 
g3::queue<T, Container>::operator!=(const queue& other) 
{
	return !(ob.size() == other.size());
}	

template <typename T, typename Container>
bool 
g3::queue<T, Container>::operator<(const queue& other) 
{
	return ob.size() < other.size();
}

template <typename T, typename Container>
bool 
g3::queue<T, Container>::operator<=(const queue& other) 
{
	return ob.size() <= other.size();
}

template <typename T, typename Container>
bool 
g3::queue<T, Container>::operator>(const queue& other) 
{
	return ob.size() > other.size();
}

template <typename T, typename Container>
bool 
g3::queue<T, Container>::operator>=(const queue& other)
{
	return ob.size() >= other.size();
}


#endif
