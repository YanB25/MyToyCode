#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<bool> isRoot;
int arr[20][2] = {};
void pre(int pos) {
    if (pos == 0)return;
    cout << pos;
    pre(arr[pos][0]);
    pre(arr[pos][1]);
}
void in(int pos) {
    if (pos == 0) return;
    in(arr[pos][0]);
    cout << pos;
    in(arr[pos][1]);
}
void post(int pos) {
    if (pos == 0) return;
    post(arr[pos][0]);
    post(arr[pos][1]);
    cout << pos;
}
int main() {
    int n;
    cin >> n;
    isRoot.resize(n + 1, true);
    for (int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        arr[i][0] = l;
        arr[i][1] = r;
        isRoot[l] = false;
        isRoot[r] = false;
    }
    int rootPos = find(isRoot.begin(), isRoot.end(), true) - isRoot.begin();
    pre(rootPos);
    cout << endl;
    in(rootPos);
    cout << endl;
    post(rootPos);
    cout << endl;
}

