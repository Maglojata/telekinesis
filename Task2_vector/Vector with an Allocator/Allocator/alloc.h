#ifndef _AL_LOC_
#define _AL_LOC_

//#include <iostream>

template <typename T>
class Allocator {
	private:
		bool flag = false;
		char storage[3000];

	public:
		using value_type = T;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = std::size_t;
	
	public:
		Allocator() = default;
		explicit Allocator(const Allocator& rhv) = default;
		~Allocator() = default;

	public:
	pointer allocate(size_type count){
		if (!flag) {
			return static_cast<pointer>(static_cast<void*>(storage));	
		} else {
			return static_cast<pointer>(static_cast<void*>(storage + 1500));
		}
		flag = !flag;
	}
	//template <typename T>
	void 
	deallocate(void* ptr, size_type count) {};
	
	template <typename ... Args>	
	void construct(pointer ptr, Args... args) {
		std::construct_at(ptr, std::forward<Args>(args)...);
	}

	void distroy(pointer ptr) {
		std::distroy_at(ptr);
	}	

		// pointer allocate(size_type count);
		// void deallocate(pointer ptr, size_type type);
		// template <typename Args ...args>
		// void construct(pointer ptr, Args ...args);
		// void distroy(pointer ptr);
		// //constexpr size_type max_size(const Allocator);

};

//#include "alloc.tpp"

#endif
