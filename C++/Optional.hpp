#ifndef _MY_OPTIONAL_HPP
#define _MY_OPTIONAL_HPP

template <typename T>
class Optional {
public:
    typedef T data_t;
    Optional() { }
    Optional(const T& data) : _data(data), isValid(true) { }
    operator bool() { return _isValid; }
    const T& get() const { return _data; }
    T& get() { return _data; }
private:
    bool _isValid= false;
    data_t _data= T();
};

#endif
