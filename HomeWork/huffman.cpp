#include <iostream>
#include <queue>
#include <string>
using namespace std;
int frequency[300] = {};
int codes[300] = {};
struct Data {
    string chs;
    int f;
    bool operator<(const Data& rhs) const  {
        return f >= rhs.f;
    }
    Data(char c, int f_) {
        chs.push_back(c);
        f = f_;
    }
    Data(const string& s, int f_) {
        chs = s;
        f = f_;
    }
};
int main() {
    int n;
    priority_queue<Data> que;
    cin >> n;
    while (n--) {
        char al; int f;
        cin >> al >> f;
        cin.get();
        frequency[al] = f;
        que.push(Data(al, f));
    }
    while (!(que.size() == 1)) {
        auto d1 = que.top(); que.pop();
        auto d2 = que.top(); que.pop();
        for (auto c : d1.chs) {
            codes[c]++;
        }
        for (auto c : d2.chs) {
            codes[c]++;
        }
        que.push(Data(d1.chs + d2.chs, d1.f + d2.f));
    }
    int sum = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        sum += frequency[i] * codes[i];
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        sum += frequency[i] * codes[i];
    }
    cout << sum << endl;
}






