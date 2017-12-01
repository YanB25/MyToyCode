#include <iostream>
using namespace std;
class Human {
public:
    virtual void wearClothes() = 0;
};

class Person : public Human {
public:
    virtual void wearClothes() { cout << "穿什么好呢。。。" << endl; }
};

// below are decorators
class Decorator : public Human {
public:
    Decorator(Human& human) : human_(human) {}
    virtual void wearClothes() { human_.wearClothes(); }
private:
    Human& human_;
};

class Decorator1 : public Decorator {
public:
    using Decorator::Decorator;
    virtual void wearClothes() {
        Decorator::wearClothes();
        cout << "去卧室找找衣服" << endl;
    }
};

class Decorator2 : public Decorator {
public:
    using Decorator::Decorator;
    virtual void wearClothes() {
        Decorator::wearClothes();
        cout << "去衣柜找找衣服" << endl;
    }
};

class Decorator3 : public Decorator {
public:
    using Decorator::Decorator;
    virtual void wearClothes() {
        Decorator::wearClothes();
        cout << "找到好看的衣服！" << endl;
    }
};

void work(Human& human) {
    human.wearClothes();
}

int main() {
    Person person;
    Decorator1 d1(person);
    Decorator2 d2(d1);
    Decorator3 d3(d2);
    //work ...
    work(person);
    cout << endl;
    work(d3);
    //finish
    return 0;
}
