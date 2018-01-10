#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct State {
    string pre;
    string in;
    State (const string& p, const string& i) {
        pre = p;
        in = i;
    }
};
void search(const State& state) {
    const string& pre = state.pre;
    const string& in = state.in;
    if (pre == "" || in == "") return;
    char root = pre[0];
    string::const_iterator itRootIn = find(in.begin(), in.end(), root);
    int leftSize = itRootIn - in.begin();

    string leftPre(pre.begin() + 1, pre.begin() + 1 + leftSize);
    string leftIn(in.begin(), itRootIn);
    string rightPre(pre.begin() + 1 + leftSize, pre.end());
    string rightIn(itRootIn + 1, in.end());
    search(State(leftPre, leftIn));
    //cout << root << " " << leftPre << " " << leftIn << " " << rightPre << " " << rightIn << endl;
    search(State(rightPre, rightIn));
    cout << root;
}
    
int main() {
    string pre;
    string in;
    cin >> pre >> in;
    search(State(pre, in));
    cout << endl;
}


