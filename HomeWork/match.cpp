#include <iostream>
#include <stack>
using namespace std;
bool isLeft(char c) {
    return c == '(' || c == '[' || c == '{';
}
int getId(char c) {
    switch (c) {
        case '(':
            return 1;
        case '[':
            return 2;
        case '{':
            return 3;
        case ')':
            return -1;
        case ']':
            return -2;
        case '}':
            return -3;
        default:
            return 0;
        }
}
bool match(char lhs, char rhs) {
    return getId(lhs) + getId(rhs) == 0;
}
int main() {
    string input;
    getline(cin, input);
    stack<char> s;
    for (const auto& item : input) {
        if (isLeft(item)) {
            s.push(item);
        } else {
            if (match(s.top(), item)) {
                s.pop();
            } else {
                cout << "Not Match" << endl;
                return 0;
            }
        }
    }
    if (!s.empty()) {
        cout << "Not Match" << endl;
    } else {
        cout << "Match" << endl;
    }
    return 0;
}
