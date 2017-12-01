#include <iostream>
using namespace std;
class Bar {
public:
    Bar() { i = 4; }
    void print() { cout << i << " " << j << endl; }
private:
    int i = 1;
    int j = 2;
};

int main() {
    Bar b;
    b.print();
    return 0;
}
