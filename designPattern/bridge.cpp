#include <string>
#include <iostream>
using namespace std;

class color {
public:
    virtual ~color() = 0;
    virtual string getColor() const = 0 ;
};
color::~color() {}

class Shape {
public:
    Shape(color* c) : color_(c) {}
    virtual ~Shape() = 0;
    virtual string getType() const = 0 ;
    string getColor() { return color_->getColor(); }
private:
    color* color_;
};
Shape::~Shape(){ delete color_;}

class Rectangle : public Shape {
public:
    Rectangle(color* c) : Shape(c) {}
    string getType() const { return "Rectangle"; }
};

class Triangle : public Shape {
public:
    Triangle(color* c) : Shape(c) {}
    string getType() const { return "Triangle"; }
};

class Red : public color {
    string getColor() const { return "Red"; }
};

class Green : public color {
    string getColor() const { return "Green"; }
};

int main() {
    Shape* rectangle = new Rectangle(new Red());
    cout << rectangle->getType() << " " << rectangle->getColor() << endl;
    Shape* triangle = new Triangle(new Green());
    cout << triangle->getType() << " " << triangle->getColor() << endl;
    delete rectangle;
    delete triangle;
    return 0;
}
