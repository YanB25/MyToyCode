#include <climits>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int deltaX[] = {1, 0, -1, 0}; //r, d, l, u
int deltaY[] = {0, 1, 0, -1};
int m, n, D;
vector<string> map;
vector<vector<int>> rmax;
bool hasVisited[110][110][110] = {};
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
bool isLand(int x, int y, int r) {
    if ( x >= 0
        && x <= n-1
        && y >= 0
        && y <= m-1
        && map[y][x] == 'P'
        && !hasVisited[y][x][r]) {
            hasVisited[y][x][r] = true;
            return true;
        } else {
            return false;
        }
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

        for (int i = 0; i < 4; ++i) {
            for (int flydst = 2; flydst <= remains; ++flydst) {
                int newx = x + deltaX[i] * flydst;
                int newy = y + deltaY[i] * flydst;
                if (isLand(newx, newy, remains-flydst)) {
                    q.push(State(newx, newy, remains - flydst, cnt + 1));
                    #ifdef DEBUG
                    cout << "x y r c " << newx << " " << newy << " " << remains-flydst << " " << cnt+1 << endl;
                    #endif
                }
            }
            if (isLand(x + deltaX[i], y + deltaY[i], remains)) {
                q.push(State(x + deltaX[i], y + deltaY[i], remains, cnt + 1));
                #ifdef DEBUG
                cout << "x y r c " << x+deltaX[i] << " " << y+deltaY[i] << " " << remains << " " << cnt+1 << endl;
                #endif
            }
        }
    }
}
int main() {
    #ifdef DEBUG
    freopen("input", "r", stdin);
    #endif
    cin >> m >> n >> D;
    rmax.resize(m);
    for (auto& v : rmax) v.resize(n, -1);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        map.push_back(s);
    }
    int cnt = Solution();
    if (cnt == -1) {
        cout << "impossible" << endl;
    } else {
        cout << cnt << endl;
    }
}
