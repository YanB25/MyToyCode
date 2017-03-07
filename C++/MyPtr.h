#ifndef _MY_PTR_
#define _MY_PTR_
#include <algorithm>

template <typename T>
class MyPtr {
public:
	MyPtr(const T& t) : ptr(new T (t)), cnt(new unsigned(1)) {}
	MyPtr() : ptr(new T()), cnt(new unsigned(1)) {}
	MyPtr(const MyPtr& t) : ptr(t.ptr), cnt(t.cnt) { (*cnt)++;} 
	MyPtr& operator=(MyPtr rhs);
	T& operator*();
	~MyPtr();
	template<typename Type> friend void swap(MyPtr<Type>&, MyPtr<Type>&);
	int count() const { return *cnt; };
private:
	T* ptr;
	unsigned* cnt;
};
template<typename T>
MyPtr<T>& MyPtr<T>::operator=(MyPtr rhs) {
	swap(*this, rhs);
	return *this;
}

#include <iostream>
template<typename T>
MyPtr<T>::~MyPtr() {
	if (--*cnt == 0) {
		delete ptr;
		delete cnt;
		std::cout << "delete" << std::endl;
	}
}

template<typename T>
T& MyPtr<T>::operator*() {
	return *ptr;
}

template <typename T>
void swap(MyPtr<T>& lhs, MyPtr<T>& rhs) {
	using std::swap;
	swap(lhs.ptr, rhs.ptr);
	swap(lhs.cnt, rhs.cnt);
}

#endif
