#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
    char c;
    stack<char> s;
    while ((c = cin.get()) && c != '\n') {
        s.push(c);
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}
    
