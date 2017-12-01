#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
int main() {
    cout << ">>> ";
    stack<int> intStack;
    stack<char> opStack;
    while (true) {
        if (isdigit(cin.peek())) {
            int num;
            cin >> num;
            intStack.push(num);
        } else (!cin.eof()) {
            char c;
            cin >> c;
            if (isBaseOp(c)) {
                char top = opStack.top();
                

