
#ifndef _STACK_
#define _STACK_

#include <vector>
#include <initializer_list>

template <typename T, typename Container = std::vector<T>>

class stack {
    private:
    Container obj;

    public:
        using value_type = T;
        using container_type = Container;
        using reference = typename container_type::reference;
        using const_reference = typename container_type::const_reference;
        using size_type = size_t;

    public:
        stack();
        explicit stack(const container_type& rhv);
        explicit stack(container_type&& rhv);
        stack(std::initializer_list<value_type> init);
        ~stack();

    public:
        const stack& operator=(const container_type& rhv);
        const stack& operator=(container_type&& rhv);

    public:
        void push(size_type elem);
        void pop();
        reference top();
        size_type size();
        void swap(container_type& other);
        bool empty();


    template <typename F, typename ContainerF>
    friend bool operator>(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
	friend bool operator<(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

	template <typename F, typename ContainerF>
	friend bool operator==(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

	template <typename F, typename ContainerF>
	friend bool operator!=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

	template <typename F, typename ContainerF>
    friend bool operator>=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

	template <typename F, typename ContainerF>
    friend bool operator<=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

};

	template <typename F, typename ContainerF>
    bool operator>(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
   	bool operator<(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
    bool operator==(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
    bool operator!=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
    bool operator>=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);

    template <typename F, typename ContainerF>
    bool operator<=(const stack<F, ContainerF>& lhv, const stack<F, ContainerF>& rhv);




#include "stack1.tpp"

#endif
         
