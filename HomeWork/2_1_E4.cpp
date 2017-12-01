#include <iostream>
#include <stack>
using namespace std;
int cnt = 0;
void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void findPermutation(stack<int> start, stack<int> terminal, stack<int> halt, bool flag) {
    if (start.empty() && halt.empty()) {
        cnt ++;
    }
    if (!start.empty()) {
        int top = start.top();

        start.pop();
        halt.push(top);
        findPermutation(start, terminal, halt, true);

        halt.pop();
        terminal.push(top);
        findPermutation(start, terminal, halt, false);

        terminal.pop();
        start.push(top);
    } 
    if (!halt.empty() && !flag) {
        int top = halt.top();
        terminal.push(top);
        halt.pop();
        findPermutation(start, terminal, halt, false);
    }
}

        

int main() {
    //int n = 3;
    //stack<int> start;
    //stack<int> terminal;
    //stack<int> halt;
    //for (int i = 0; i < 100; ++i) {
    //    start.push(i);
    //    cnt = 0;
    //    findPermutation(start, terminal, halt, false);
    //    cout << i + 1 << " : " << cnt << endl;
    //}
    // 
    // 下面实现一个数值解
    unsigned long long cnt[10000] = {};
    cnt[0] = 1;
    cout << 0 << " : " << 1 << endl;
    for (int i = 1; i < 10000; ++i) {
        for (int k = 0; k < i; ++k) {
            cnt[i] += cnt[k] * cnt[i - 1 - k]; 
        }
        if (cnt[i] < cnt[i - 1]) return 0;
        cout << i << " : " << cnt[i] << endl;
    }
    return 0;
}
