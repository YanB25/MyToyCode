
//ainimal.h
#include <cstdio>
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

//human.h
//#include "animal.h"
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

#include <iostream>
#include <string>

int main() {
    std::string s, n;
    int e;
    std::cin >> s >> e >> n;
    animal * p = new animal(s, e);
    p->print_eyes();
    delete p;
    human h(n);
    p = &h;
    p->print_eyes();
    const human & q = h;
    q.greeting();
    return 0;
}





