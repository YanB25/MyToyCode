#include <iostream>
#include <functional>
#include <string>
using namespace std;
int main() {
    std::hash<std::string> h;
    int n = h("hello world");
    int n2 = h("hello worle");
    cout << n << endl;
    cout << n2 << endl;
    return 0;
}
