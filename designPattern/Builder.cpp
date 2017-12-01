#include <cstddef>
#include <string>
#include <iostream>
using namespace std;
class Food{
public:
    virtual ~Food() = 0;
private:
};
Food::~Food() {}

// elemental food
class Ice : public Food {
public:
    Ice() { cout << "Pick " "Ice"  << endl; }
};

class Water : public Food {
public:
    Water() { cout << "Pick " "Water"  << endl; }
};


class Coke : public Food {
public:
    Coke() { cout << "Pick " "Coke"  << endl; }
};

class Juice : public Food {
public:
    Juice() { cout << "Pick " "Juice"  << endl; }
};

class Milk : public Food {
public:
    Milk() { cout << "Pick " "Milk"  << endl; }
};


// complicated food
class Drink : public Food{
public:
    virtual void setIceOrWator(Food* m) { iceOrWater = m; cout << "put in ice or water" << endl;}
    virtual void setContains(Food* m) { contains = m; cout << "put in contains" << endl; }
    ~Drink() { delete iceOrWater; delete contains; iceOrWater = nullptr; contains = nullptr; }
private:
    Food* iceOrWater = nullptr;
    Food* contains = nullptr;
};
// ========================================
class Builder {
public:
    virtual void build() = 0;
    virtual Food* getResult() = 0;
};

class Make_IceJuice : public Builder {
public:
    virtual void build(); 
    Drink* getResult() { return drink_; }
    ~Make_IceJuice() { delete drink_;  drink_ = nullptr;}
private:
    Drink* drink_;
    void putIce() { drink_->setIceOrWator(new Ice());}
    void putContains() { drink_->setContains(new Juice()); }
    void init() { drink_ = new Drink(); cout << "init a drink" << endl;}
};

void Make_IceJuice::build() { 
    init();
    putIce();
    putContains(); 
}

class Make_WaterMilk : public Builder {
public:
    virtual void build();
    Drink* getResult() { return drink_; }
    ~Make_WaterMilk() { delete drink_; drink_ = nullptr; }
private:
    Drink* drink_;
    void putWater() { drink_->setIceOrWator(new Water());}
    void putContains() { drink_->setContains(new Milk());}
    void init() { drink_ = new Drink(); cout << "init a drink" << endl; }
};
void Make_WaterMilk::build() {
    init();
    putContains();
    putWater();
}

class Waitor {
public:
    void setMeal(Builder* builder) { builder_ = builder; cout << "Waitor: begin to make the meal" << endl; }
    Food* getFood() { builder_->build(); cout << "Waitor: here is your meal" << endl; return builder_->getResult(); }
private:
    Builder* builder_;
};
// ====================================================
int main() {
    Waitor waitor;
    Make_IceJuice ice_juice;
    waitor.setMeal(&ice_juice);
    auto food = waitor.getFood();
    
    Make_WaterMilk water_milk;
    waitor.setMeal(&water_milk);
    auto food2 = waitor.getFood();
    return 0;
}
