#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <memory>
#include <utility>
#include <iostream>
using std::cout;
using std::endl;
using std::allocator;
using std::pair;
using std::uninitialized_copy;
template<typename T>
class vector {
public:
	vector() : elements(nullptr), first_free(nullptr), cap(nullptr) {};
	vector(const vector&);
	vector(vector&& s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
		s.elements = s.first_free = s.cap = nullptr;
		cout << "call move construct" << endl;
	}
	vector& operator=(const vector&);
	vector& operator=(vector&&) noexcept;
	T& operator[](size_t i) { return *(elements + i); }
	const T& operator[](size_t i) const { return *(elements + i); }
	~vector();
	void push_back(const T&);
	void push_back(T&& );
	template <typename ...Args> void emplace_back(Args&&... );
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	T* begin() const { return elements; }
	T* end() const { return first_free; }
private:
	allocator<T> alloc;
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void reallocate();
	void free();
	T* elements;
	T* first_free;
	T* cap;
};

template<typename T>
void vector<T>::push_back(const T& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
	cout << "call push_back" << endl;//
}

template<typename T>
void vector<T>::push_back(T&& s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
}

template <typename T> template <typename ...Args>
void vector<T>::emplace_back(Args&&... args) {
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
	cout << "call emplace_back" << endl;
}

template<typename T>
pair<T*, T*> vector<T>::alloc_n_copy(const T* b, const T* e) {
	T* newAlloc = alloc.allocate(e - b);
	return { newAlloc, uninitialized_copy(b, e, newAlloc) };
}
template<typename T>
void vector<T>::free() {
	if (elements) {
		while (first_free != elements) {
			alloc.destroy(--first_free);
		}
	}
	alloc.deallocate(elements, capacity());
}

template<typename T>
vector<T>::vector(const vector<T>& s) {
	auto newAlloc = alloc_n_copy(s.begin(), s.end());
	elements = newAlloc.first;
	cap = first_free = newAlloc.second;
	cout << "call copy construct" << endl;
}

template<typename T>
vector<T>::~vector<T>() {
	free();
	cout << "destruct" << endl;
}
	
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& rhs) {
	auto newData = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newData.first;
	first_free = cap = newData.second;
	cout << "cpy assigned" << endl;
	return *this;
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T>&& rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		cap = rhs.cap;
		first_free = rhs.first_free;
		rhs.cap = rhs.elements = rhs.first_free = nullptr;
	}
	cout << "call move assignment" << endl;//
	return *this;
}
		
template<typename T>
void vector<T>::reallocate() {
	int newCapacity = size() == 0 ? 1 : 2 * size();
	auto newElements = alloc.allocate(newCapacity);
	auto elem = newElements;
	for (auto i = elements; i != first_free; ++i) {
		alloc.construct(newElements++, std::move(*i));
	}
	free();
	elements = elem;
	first_free = newElements;
	cap = elements + newCapacity;
}
	
















#endif
