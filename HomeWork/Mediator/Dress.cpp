#include "Dress.hpp"
Dress::Dress(const string& name, const int price): name(name), price(price) {}
Dress::Dress(const Dress& rhs) {
    name = rhs.name;
    price = rhs.price;
}
int Dress::getPrice() const { return price; }
string Dress::getName() const { return name; }


