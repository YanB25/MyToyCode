#include <iostream>
using namespace std;
int main() {
    const int a = 3;
    int* p = (int*) &a;
    *p = 8;
    cout << &a << endl << a << endl << p << endl << *p << endl;
}
