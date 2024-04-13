#ifndef _S__T_
#define _S__T_

#include "stack1.h"

template <typename T, typename Container>
stack<T, Container>::stack()
	: obj()
{}

template <typename T, typename Container>
stack<T, Container>::stack(const container_type& rhv)
	: obj{rhv.obj}
{}

template <typename T, typename Container>
stack<T, Container>::stack(container_type&& rhv)
	: obj{rhv.obj}
{
	rhv.obj = 0;
}

template <typename T, typename Container>
stack<T, Container>::stack(std::initializer_list<value_type> init) {
for (auto &i : init) {
	obj.push_back(i);
}
}

template <typename T, typename Container>
stack<T, Container>::~stack()
{}

template <typename T, typename Container>
const stack<T, Container>&
stack<T, Container>::operator=(const container_type& rhv) {
	if (this != &rhv){
		obj.clear();		
		obj = rhv.obj;
	}
	return *this;
}

template <typename T, typename Container> 
const stack<T, Container>& 
stack<T, Container>::operator=(container_type&& rhv){
	if (this != &rhv){
		obj.clear();	
		obj = std::move(rhv.obj);
	}
	return *this;
}

template <typename T, typename Container>
void 
stack<T, Container>::pop(){
	obj.pop_back();
}

template <typename T, typename Container>
void
stack<T, Container>::push(size_type elem){
	obj.push_back(elem);
}

template <typename T, typename Container>
typename stack<T, Container>::reference
stack<T, Container>::top() {
	return obj.back();
}

template <typename T, typename Container>
typename stack<T, Container>::size_type
stack<T, Container>::size(){
	return obj.size();
}

template <typename T, typename Container>
void
stack<T, Container>::swap(container_type& other){
	obj.swap(other);
}

template <typename T, typename Container>
bool 
stack<T, Container>::empty(){
	return obj.empty();
}


template <typename F, typename ContainerF>
bool 
operator>(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv) {
	return lhv.obj > rhv.obj;
}

template <typename F, typename ContainerF>
bool 
operator<(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv) {
    return lhv.obj < rhv.obj;
}

template <typename F, typename ContainerF>
bool 
operator==(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv) {
	return lhv.obj == rhv.obj;
}

template <typename F, typename ContainerF>
bool 
operator!=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv) {
	return !(lhv.obj = rhv.obj);
}

template <typename F, typename ContainerF>
bool
operator<=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv) {
	return lhv.obj <= rhv.obj;
}

template <typename F, typename ContainerF>
bool
operator>=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv){
	return lhv.obj >= rhv.obj;
}


#endif
