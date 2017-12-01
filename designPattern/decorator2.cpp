#include <string>
#include <iostream>
using namespace std;

class Hamburger {
public:
    virtual string getName() = 0;
    virtual double getPrice() = 0;
};

class ChickenHanburger : public Hamburger {
public:
    virtual string getName() { return "chicken hamburger"; }
    virtual double getPrice() { return 10; }
};

class SpecialHamburger : public Hamburger {
public:
    SpecialHamburger(Hamburger& h) : hamburger_(h){}
    virtual string getName() { return hamburger_.getName(); }
    virtual double getPrice() { return hamburger_.getPrice(); }
private:
    Hamburger& hamburger_;
};

class VegetableHamburger : public SpecialHamburger {
public:
    using SpecialHamburger::SpecialHamburger;
    virtual string getName() { return SpecialHamburger::getName() + " plus vegetable"; }
    virtual double getPrice() { return SpecialHamburger::getPrice() + 5; }
};

class SpicyHamburger : public SpecialHamburger {
public:
    using SpecialHamburger::SpecialHamburger;
    virtual string getName() { return SpecialHamburger::getName() + " with pepper "; }
    virtual double getPrice() { return SpecialHamburger::getPrice() + 2; } 
};

void Show(Hamburger& hamburger) {
    cout << hamburger.getName() << " : " << hamburger.getPrice() << " $ " << endl;
}

int main() {
    ChickenHanburger chicken_hamburger;
    VegetableHamburger vegetable_hamburger(chicken_hamburger);
    SpicyHamburger spicy_hamburger(chicken_hamburger);
    SpicyHamburger spicy_and_vegetable_hamburger(vegetable_hamburger);

    Show(chicken_hamburger);
    Show(vegetable_hamburger);
    Show(spicy_hamburger);
    Show(spicy_and_vegetable_hamburger);
    
    return 0;
}

