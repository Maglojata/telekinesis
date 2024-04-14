#ifndef _FIFO_
#define _FIFO_

#include "queue.h"

//constructor
template <typename T, typename Container>
queue<T, Container>::queue()
	: ob()
{}


//copy constructor
template <typename T, typename Container>
queue<T, Container>::queue(const queue& rhv)
	: ob{rhv.ob}
{}


//move constructor
template <typename T, typename Container>
queue<T, Container>::queue(queue&& rhv)
	: ob{std::move(rhv.ob)}
{
	rhv.ob.clear();
}

template <typename T, typename Container>
queue<T, Container>::queue(std::initializer_list<value_type> init) {
	for (auto &i : init) {
		ob.push_back(i);
	}
}

//destructor
template <typename T, typename Container>
queue<T, Container>::~queue()
{}


//copy assignment
template <typename T, typename Container>
const queue<T, Container>&
queue<T, Container>::operator= (const container_type& other) {
	if (this != &other) {
		ob.clear();
		ob = other.ob;
 }
	return *this;
}


//move assignment 
template <typename T, typename Container>
const queue<T, Container>& 
queue<T, Container>::operator=(container_type&& other) {
	if (this != &other) {
		ob.clear();
		ob = std::move(other.ob);
	}
	return *this;
}

template <typename T, typename Container>
typename queue<T, Container>::reference
queue<T, Container>::front(){
    return ob.front();
}

template <typename T, typename Container>
typename queue<T, Container>::reference
queue<T, Container>::back(){
    return ob.back();
}

template <typename T, typename Container>
bool
queue<T, Container>::empty(){
	return ob.empty();
}

template <typename T, typename Container>
typename queue<T, Container>::size_type
queue<T, Container>::size(){
    return ob.size();
}

template <typename T, typename Container>
void
queue<T, Container>::push(const value_type& value){
    ob.push_back(value);
}

template <typename T, typename Container>
void
queue<T, Container>::push(value_type&& value){
    ob.push_back(std::move(value));
}

template <typename T, typename Container>
void
queue<T, Container>::pop(){
    ob.pop_front();
}

template <typename T, typename Container>
void
queue<T, Container>::swap(queue& other){
    ob.swap(other.ob);
}


template <typename Q, typename ContainerQ>
bool 
operator ==(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv){
	return lhv.ob == rhv.ob;
	}

template <typename Q, typename ContainerQ>
bool 
operator !=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv){
	return lhv.ob != rhv.ob;
}

template <typename Q, typename ContainerQ>
bool 
operator<(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv){
	return lhv.ob < rhv.ob;
}

template <typename Q, typename ContainerQ>
bool 
operator <=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv){
	return lhv.ob <= rhv.ob;
}

template <typename Q, typename ContainerQ>
bool 
operator >(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv){
	return lhv.ob > rhv.ob;
}

template <typename Q, typename ContainerQ>
bool 
operator >=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv) {
	return lhv.ob >= rhv.ob;
}


#endif
