
class array {
  typedef int* pointer;
  typedef unsigned int size_t;
  typedef int data_type;
 
  pointer _data;
  size_t _size;
 
 public:
  // constructor
  array(size_t size);
  // destructor
  ~array();
  // Capacity
  // Return maximum size
  size_t max_size(void);
 
  // Element access
  // Access element
  // int& operator[](const int &i) {return data[i];}
  // Access element
  data_type& at(const data_type& i);
  // Access first element
  data_type& front();
  // Access last element
  data_type& back();
  // Get pointer to data
  pointer data();
 
  // Modifiers
  // Fill array with the same value
  void fill(const data_type& value);
  // Resize the array (newSize > oldSize)
  void resize(int newSize);
  // Sort the array in the section [from, to)
  void sort(int from, int to);
};
 
 
#include <iostream>
 
int main() {
  int n;
 
  std::cin >> n;
 
  array a(n);
 
  for (int i = 0; i < n; i++) {
    std::cin >> a.data()[i];
  }
 
  std::cout << "array size:" << a.max_size() << std::endl;
  std::cout << "array front:" << a.front() << std::endl;
  std::cout << "array back:" << a.back() << std::endl;
 
  int* data = a.data();
  std::cout << "array elements using data:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
 
  std::cout << "array elements using at:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  std::cout << "array fill:" << std::endl;
  a.fill(9);
  for (int i = 0; i < n; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  for (int i = 0; i < n; i++) {
    std::cin >> a.at(i);
  }
 
  std::cout << "array assign:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  std::cout << "sort the array:" << std::endl;
  a.sort(0, a.max_size());
  for (int i = 0; i < n; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  int m;
  std::cin >> m;
 
  a.resize(n + m);
 
  for (int i = n; i < n + m; i++) {
    std::cin >> a.at(i);
  }
 
  std::cout << "resize and then input:(max size:" << a.max_size() << ")"
            << std::endl;
  for (int i = 0; i < n + m; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  std::cout << "resize and then sort:" << std::endl;
 
  a.sort(n + m / 2, m + n);
 
  for (int i = n + m / 2; i < n + m; i++) {
    std::cout << a.at(i) << " ";
  }
  std::cout << std::endl;
 
  return 0;
}
 









#include <algorithm>
array::array(size_t size) : _size(size) {
	_data = new int[_size]();
}

array::~array() {
	delete[] _data;
	_data = nullptr;
	_size = 0;
}

array::size_t array::max_size(void) { return _size; }

array::data_type& array::at(const data_type& i) { return _data[i]; }

array::data_type& array::front() { return _data[0]; }
  // Access last element
array::data_type& array::back() { return _data[_size - 1]; }

array::pointer array::data() { return _data; }

void array::fill(const data_type& value) {
	for (int i = 0; i < _size; ++i ){
		_data[i] = value;
	}
}

void array::resize(int newSize) {
	int* arr = new int[newSize]();
	for (int i = 0; i < _size; ++i) {
		arr[i] = _data[i];
	}
	
	delete[] _data;
	_data = arr;
	_size = newSize;
}

void array::sort(int from, int to) {
	int* beg = _data + from;
	int* end = _data + to;
	std::sort(beg, end);
}





