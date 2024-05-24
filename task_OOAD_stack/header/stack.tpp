#ifndef __STACK__TPP__
#define __STACK__TPP__

#include "stack.h"

template <typename T, typename Container>
g3::stack<T, Container>::stack()
	: ob()
{}

template <typename T, typename Container>
g3::stack<T, Container>::stack(const stack& rhv)
	: ob{rhv.obj}
{}

template <typename T, typename Container>
g3::stack<T, Container>::stack(stack&& rhv) 
	: ob{rhv.obj}
{
	rhv.ob = 0;
}
    
template <typename T, typename Container>
g3::stack<T, Container>::stack(std::initializer_list<value_type> init)
{
	for (auto &i : init) {
		ob.push_back(i);
	}
}

   // template <typename InputIt>
    //stack(InputIt first, InputIt last);
    
template <typename T, typename Container>
g3::stack<T, Container>::~stack()
{}

template <typename T, typename Container>
const g3::stack<T, Container>&
g3::stack<T, Container>::operator=(const stack& rhv) 
{
	if (this != &rhv) {
		ob.clear();
		ob = rhv.ob;
	}
	return *this;
} 

template <typename T, typename Container>
const g3::stack<T, Container>&
g3::stack<T, Container>::operator=(stack&& rhv)
{
	if (this != &rhv) {
		ob.clear();
		ob = std::move(rhv.ob);
	}
	return *this;
}

template <typename T, typename Container>
typename g3::stack<T, Container>::reference 
g3::stack<T, Container>::top()
{
	return ob.back();
}

template <typename T, typename Container>
typename g3::stack<T, Container>::const_reference 
g3::stack<T, Container>::top() const
{
	return ob.back();
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::empty() const
{
	return ob.empty();
}
    
template <typename T, typename Container>
typename g3::stack<T, Container>::size_type
g3::stack<T, Container>::size() const
{
	return ob.size();
}

template <typename T, typename Container>
void
g3::stack<T, Container>::push(const_reference val)
{
	ob.push_back(val);
}

template <typename T, typename Container>
void
g3::stack<T, Container>::pop()
{
	ob.pop_back();
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::operator==(const stack& other)
{
	return (ob.size() == other.size());
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::operator!=(const stack& other)
{
    return !(ob.size() == other.size());
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::operator<(const stack& other)
{
    return (ob.size() < other.size());
}
   
template <typename T, typename Container>
bool
g3::stack<T, Container>::operator<=(const stack& other)
{
    return (ob.size() <= other.size());
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::operator>(const stack& other)
{
    return (ob.size() > other.size());
}

template <typename T, typename Container>
bool
g3::stack<T, Container>::operator>=(const stack& other)
{
    return (ob.size() >= other.size());
}


#endif
