#include <iostream>
#include <set>
#include <utility>
#include <string>
#include <vector>
using namespace std;
vector<string> codes;
bool min(int l, int r) { return l < r ? l : r;}
int main() {
    int n;
    cin >> n;
    codes.resize(256);
    set<pair<int, string>> s; 
    for (int i = 0; i < n; ++i) {
        char c; int f;
        cin >> c >> f;
        s.insert(pair<int, string>(f, string(1, c)));
    }
    while (s.size() != 1) {
        auto t1 = s.begin(); s.erase(s.begin());
        auto t2 = s.begin(); s.erase(s.begin());
        for (auto i : t1->second) {
            codes[i] = "0" + codes[i];
        }
        for (auto i : t2->second) {
            codes[i] = "1" + codes[i];
        }
        s.insert(pair<int, string>(t1->first+t2->first, t1->second + t2->second));
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        cout << char(i) << "\t" <<  codes[i] << endl;
    }
}