#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int n;
string str, target;
int step[5];
struct State {
    int i;
    int j;
    vector<int> _hasVisit;
    State(int i_, int j_) {
        i = i_;
        j = j_;
        _hasVisit.push_back(i);
    }
    bool hasVisit(int i) {
        for (auto item : _hasVisit) {
            if (item == i) return true;
        }
        return false;
    }
};
bool check(int i) {
    return i >= 0 && i < str.size();
}
bool bfs() {
    int msize = sqrt(str.size());
    for (int i = 0; i < str.size(); ++i) {
        queue<State> q;
        q.push(State(i, 0));
        while (!q.empty()) {
            State s = q.front(); q.pop();
            int pos = s.i;
            int dst = s.j;
            if (str[pos] != target[dst]) continue;
            if (dst == target.size()-1) {
                for (auto ttt : s._hasVisit) {
                    cout << ttt << " ";
                }
                cout << endl;
                return true;
            }
            for (int t = 0; t < 4; ++t) {
                if (step[t] == 1 && i % msize == msize-1) continue;
                if (step[t] == -1 && i % msize == 0) continue;
                if (check(pos + step[t]) && ! s.hasVisit(pos + step[t])) {
                    if (str[i] == 'a') cout << i << " " << step[t] << " " << msize << endl;
                    State newState(pos + step[t], dst+1);
                    q.push(newState);
                }
            }
        }
    }
    return false;
}


int main() {
    cin >> n;
    while (n--) {
        cin >> str >> target;
        step[0] = 1;
        step[1] = -1;
        step[2] = sqrt(str.size());
        step[3] = -sqrt(str.size());
        cout << bfs() << endl;
    }
}
