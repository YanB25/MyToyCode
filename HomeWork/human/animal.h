 
//ainimal.h
#include <string>
#include <iostream>
using namespace std;
class animal {
public:
    animal() : _eyes(0) { }
    animal(const string& s, int e) : _species(s), _eyes(e) { }
    void print_eyes() const { printf("species has %d eyes.", _eyes); }
private:
    string _species;
    int _eyes;
};


