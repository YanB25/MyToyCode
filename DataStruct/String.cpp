#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
class String {
public:
    String();
    String(const char* const);
    String(const String& rhs);
    String& operator=(String s);
    ~String();

    void clear();
    int size() const;
    int length() const;
    int capacity() const;
    bool empty() const;
    char operator[](int pos) const;
    char& operator[](int pos);
    String operator+(const String& rhs);
    String& operator+=(const String& rhs);
    int find(const String& rhs);
    char* c_str() const;
private:
    char* buff_;
    int size_;
    int capacity_;
};
String::String() : buff_(nullptr), size_(0), capacity_(0){}
String::String(const char* const rhs) : String() {
    size_ = strlen(rhs);
    capacity_ = size_ + 1;
    buff_ = new char[capacity_];
    strcpy(buff_, rhs);
}
String::String(const String& rhs) : String(rhs.buff_) { }
String& String::operator=(String s) {
    std::swap(buff_, s.buff_);
    std::swap(size_, s.size_);
    std::swap(capacity_, s.capacity_);
    return *this;
}

String::~String() {
    clear();
}

void String::clear() {
    delete[] buff_;
    buff_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}
int String::size() const { return size_; }
int String::length() const { return size(); }
int String::capacity() const { return capacity_; }
bool String::empty() const { return size_ == 0; }
char String::operator[](int pos) const { return buff_[pos]; }
char& String::operator[](int pos) { return buff_[pos]; }
String& String::operator+=(const String& rhs) {
    char* tmp = new char[capacity_];
    strcpy(tmp, buff_);
    delete[] buff_;
    size_ = size_ + rhs.size_;
    capacity_ = size_ + 1;
    buff_ = new char[capacity_];
    strcpy(buff_, tmp);
    strcat(buff_, rhs.buff_);
    return *this;
}
String String::operator+(const String& rhs) {
    String ret(*this);
    ret += rhs;
    return ret;
}

int String::find(const String& rhs) {
    int index = 0;
    for (int i = 0; i < size_; ++i) {
        index = i;
        for (int j = 0;j < rhs.size_; ++j) {
            if (i + j >= size_ || rhs[j] != (*this)[i + j]) {
                index = -1;
            }
        }
        if (index != -1) return index;
    }
    return index;
}
char* String::c_str() const {
    return buff_;
}
int main() {
    String s("hello world");
    String s2("hs");
    s2 += s;
    printf("%s\n", s2.c_str());
    return 0;
}
