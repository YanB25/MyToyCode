#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    stack<int> s;
    s.push(n);
    do {
outer:
        int top = s.top();
        for (int i = 2; i < top; ++i) {
            if (top % i == 0) {
                s.pop();
                s.push(i);
                s.push(top / i);
                goto outer;
            }
        }
    } while (false);
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}   

