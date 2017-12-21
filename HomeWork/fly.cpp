#include <climits>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int m, n, D;
vector<string> map;
vector<vector<int>> rmax;
struct State {
    int x;
    int y;
    int remains;
    int cnt;
    State(int x_, int y_, int r_, int c_) {
        x = x_;
        y = y_;
        remains = r_;
        cnt = c_;
    }
};
bool isLand(int x, int y) {
    return map[y][x] == 'P';
}
int Solution() {
    int dx = n-1, dy = m-1;
    State s(0,0,D,0);
    queue<State> q;
    q.push(s);
    while (true) {
        if (q.empty()) return -1;
        State s = q.front(); q.pop();
        int x = s.x; int y = s.y; int remains = s.remains; int cnt = s.cnt;
        if (x == dx && y == dy) return cnt;
        if (remains < rmax[y][x]) continue;
        rmax[y][x] = remains;
        #ifdef DEBUG
        //cout << "x y r c " << x << " " << y << " " << remains << " " << cnt << endl;
        #endif

        for (int flydst = 2; flydst <= remains; ++flydst) {
            if (x + flydst <= dx && isLand(x+flydst, y)) {
                q.push(State(x+flydst, y,remains-flydst, cnt+1));
            }
            if (x - flydst >= 0 && isLand(x-flydst, y)) {
                q.push(State(x-flydst, y, remains-flydst, cnt+1));
            }
            if (y + flydst <= dy && isLand(x, y+flydst)) {
                q.push(State(x, y+flydst, remains-flydst, cnt+1));
            }
            if (y - flydst >= 0 && isLand(x, y-flydst)) {
                q.push(State(x, y-flydst, remains-flydst, cnt+1));
            }
        }
        if (x + 1 <= dx && isLand(x+1, y)) {
            q.push(State(x+1, y,remains, cnt+1));
        }
        if (x - 1 >= 0 && isLand(x-1, y)) {
            q.push(State(x-1, y, remains, cnt+1));
        }
        if (y + 1 <= dy && isLand(x, y+1)) {
            q.push(State(x, y+1, remains, cnt+1));
        }
        if (y - 1 >= 0 && isLand(x, y-1)) {
            q.push(State(x, y-1, remains, cnt+1));
        }
    }
}
int main() {
    #ifdef DEBUG
    freopen("input", "r", stdin);
    #endif
    cin >> m >> n >> D;
    rmax.resize(m);
    for (auto& v : rmax) v.resize(n, INT_MIN/10);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        map.push_back(s);
    }
    int cnt = Solution();
    cout << cnt << endl;
}