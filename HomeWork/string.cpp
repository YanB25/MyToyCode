#include <iostream>
#include <cstring>
#include <string>
using namespace std;
 
class String {
  private:
    char *_buff;
    int _length, _size;  // _size is of the allocated memory
 
  public:
    // constructors
    String();
    explicit String(const char *src);
    String(const String &src);
    // destructor
    ~String();
    // member methods
    void assign(const char *src);
    void append(const char &other);
    void clear();
    int compare(const String &other) const;
    const char* c_str() const;
    bool empty() const;
    int find(const String &other, int pos = 0) const;
    int length() const;
    String substr(const int &pos, const int &count) const;
    // overload operators
    char& operator[](const int &index);
    void operator=(const String &other);
    void operator=(const char *src);
    String operator+(const String &other) const;
    bool operator<(const String &other) const;
    bool operator<=(const String &other) const;
    bool operator>(const String &other) const;
    bool operator>=(const String &other) const;
    bool operator==(const String &other) const;
    bool operator!=(const String &other) const;
    // friend methods
    friend std::ostream& operator<<(std::ostream& out, const String &str);
    // non-meaning static property
    static char _error_sign;  // initial as any char is okay
};
 



 
String a, b("MFGZ!");
String c = b;
 
void display() {
  cout << a.empty() << " " << a.length() << " " << a << endl;
  cout << b.empty() << " " << b.length() << " " << b << endl;
  cout << c.empty() << " " << c.length() << " " << c << endl;
}
 
int main() {
  string aa, bb, cc;
  display();
  c[0] = 'K';
  display();
  cin >> aa >> cc;
  a.assign(aa.c_str());
  c.assign(cc.c_str());
  display();
  b.clear();
  display();
  for (int i = 0 ; i < 10; ++i) {
      char t;
      cin >> t;
      a.append(t);
      b.append(t);
      c.append(t);
  }
  display();
  b = c;
  display();
  b = a + c;
  display();
  cout << a.find(String("1993")) << endl;
  cout << b.find(String("HYOUKA")) << endl;
  cout << c.find(String("RIKKA")) << endl;
  cout << a.substr(0, 3) << endl;
  cout << b.substr(3, 8) << endl;
  cout << c.substr(6, 1) << endl;
  cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
  cout << a.compare(b) << b.compare(a) << endl;
  cout << (a > c) << (a >= c) << (a < c) << (a <= c) << (a == c) << endl;
  cout << a.compare(c) << c.compare(a) << endl;
  b = a;
  cout << a << endl << b << endl;
  cout << (a > b) << (a >= b) << (a < b) << (a <= b) << (a == b) << endl;
  cout << a.compare(b) << b.compare(a) << endl;
  cout << a.compare(a) << endl;
  return 0;
}
 








#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
String::String() {
	_buff = nullptr;
	_length = _size = 0;
}

String::String(const char *src) {
	size_t pos = 0;
	_size = strlen(src) + 1;
	_length = strlen(src);
	_buff = new char[_size];
	while(src[pos] != '\0') {
		_buff[pos] = src[pos];
		pos++;
	}
	_buff[pos] = '\0';
}

String::String(const String &src) {
	_size = src._size;
	_length = src._length;
	_buff = new char[_size];
	for (int i = 0; i < _length; ++i) {
		_buff[i] = src._buff[i];
	}
	_buff[_length] = src._buff[_length];
}

String::~String() {
	clear();
}

void String::assign(const char *src) {
	this->~String();
	*this = String(src);
}

const char* String::c_str() const {
	return _buff;
}

void String::append(const char &other) {
	int new_length = _length + 2;
	char* arr = new char[_length + 2];
	for (int i = 0; i < _length; ++i) {
		arr[i] = _buff[i];
	}
	arr[_length] = other;
	arr[_length + 1] = '\0';
	clear();
	_buff = arr;
	_size = new_length;
	_length = new_length - 1;
}

void String::clear(){
	delete[] _buff;
	_buff = nullptr;
	_size = 0;
	_length = 0;
}

int String::compare(const String &other) const {
	int cmp = strcmp(c_str(), other.c_str());
	if (cmp < 0)
		return -1;
	else  if (cmp == 0)	
		return 0;
	return 1;
}

bool String::empty() const { return _size == 0; }

int String::find(const String &other, int pos) const {
	bool hasFind = true;
	for (int i = pos; i < _length; ++i) {
		hasFind = true;
		for (int j = 0; j < other._length; ++j) {
			if (_buff[i + j] != other._buff[j]) hasFind = false;
			if (j == other._length - 1 && hasFind == true) return i;
		}
	}
	return _length;
}

String String::substr(const int &pos, const int &count) const {
	assert(pos + count < _length);
	char tmp[count + 1];
	for (int i = 0; i < count; ++i) {
		tmp[i] = _buff[pos + i];
	}
	tmp[count] = '\0';
	return String(tmp);
}

char& String::operator[](const int &index) {
	assert(index < _length);
	return _buff[index];
}

void String::operator=(const String &other) {
	String tmp(other);
	clear();
	_size = other._size;
	_length = other._length;
	_buff = new char[_size];
	for (int i = 0; i < _length; ++i) {
		_buff[i] = other._buff[i];
	}
	_buff[_length] = '\0';
}
void String::operator=(const char *src) {
	String tmp(src);
	clear();
	*this = tmp;
}

String String::operator+(const String &other) const {
	int len = _length + other._length;
	char arr[len];
	strcpy(arr, _buff);
	for (int i = _length; i < len; ++i) {
		arr[i] = other._buff[i - _length];
	}
	return String(arr);
}
 int String::length() const { return _length;}
bool String::operator<(const String &other) const {
	return strcmp(c_str(), other.c_str()) < 0;
}

bool String::operator<=(const String &other) const {
	return *this < other || *this == other;
}
    
bool String::operator>(const String &other) const {
	return !(*this < other) && !(*this == other);
}
bool String::operator>=(const String &other) const {
	return *this > other || *this == other;
}
bool String::operator==(const String &other) const {
	return strcmp(_buff, other._buff) == 0;
}
bool String::operator!=(const String &other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const String &str) {
	for (int i = 0; i < str._length; ++i) {
		out << str._buff[i];
	}
	return out;
}
		
