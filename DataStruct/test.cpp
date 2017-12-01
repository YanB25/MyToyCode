#include <algorithm>
#include <iostream>
using namespace std;
class Bar {
public:
    int age = 2;
    int year = 5;
    Bar(){}
};
int main() {
    Bar b1;
    Bar b2;
    b2.age = 4;
    b2.year = 6;
    swap(b1, b2);
}
