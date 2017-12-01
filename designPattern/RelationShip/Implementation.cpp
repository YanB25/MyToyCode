#include <iostream>
using namespace std;

class Interface_readable {
public:
    virtual void read() = 0;
};

class Book : public Interface_readable {
public:
    void read() { cout << "the content for a book." << cout; } 
};
