 
//human.h
#include "animal.h"
#include <string>
#include <iostream>
using namespace std;
class human : public animal {
public:
    human(const string& name) : animal("Human", 2), _name(name) { }
    void greeting() const  { printf("Hello, I'm %s.", _name.c_str()); }
private:
    string _name; 
};


