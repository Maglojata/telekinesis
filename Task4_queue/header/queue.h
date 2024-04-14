#ifndef _QUEUE_
#define _QUEUE_

#include <list>
#include <initializer_list>

template <typename T, typename Container = std::list<T>>

class queue {
	private: 
		Container ob;

	public:
		using container_type = Container;
		using value_type = typename Container::value_type;
		using size_type = typename Container::size_type;
		using reference = typename Container::reference;
		using const_reference = typename Container::const_reference;
 
	public:
		queue();
		queue(const queue& rhv);
		queue(queue&& rhv);
		queue(std::initializer_list<value_type> init);
		~queue();

	public:
		const queue& operator=(const container_type& other);
		const queue& operator=(container_type&& other);

	public:
		reference front();
		reference back();
		bool empty();
		size_type size();
		void push(const value_type& value);
		void push(value_type&& value);
		void pop();
		void swap(queue& other);
		
	template <typename Q, typename ContainerQ>
	friend bool operator ==(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);
	
	template <typename Q, typename ContainerQ>
	friend bool operator !=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

	template <typename Q, typename ContainerQ>
	friend bool operator<(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

	template <typename Q, typename ContainerQ>
	friend bool operator <=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

	template <typename Q, typename ContainerQ>
	friend bool operator >(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

	template <typename Q, typename ContainerQ>
	friend bool operator >=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

};
    template <typename Q, typename ContainerQ>
    bool operator ==(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

    template <typename Q, typename ContainerQ>
    bool operator !=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

    template <typename Q, typename ContainerQ>
    bool operator<(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

    template <typename Q, typename ContainerQ>
    bool operator <=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

    template <typename Q, typename ContainerQ>
    bool operator >(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);

    template <typename Q, typename ContainerQ>
    bool operator >=(const queue<Q, ContainerQ>& lhv, const queue<Q, ContainerQ>& rhv);


#include "queue.tpp"

#endif
