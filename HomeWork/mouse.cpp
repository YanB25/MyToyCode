#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n;
vector<vector<bool>> map;
vector<vector<bool>> hasVisit;
bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && map[y][x] == 0 && !hasVisit[y][x];
}
int dx[] = { 0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct State {
    int x;
    int y;
    int cnt;
    State(int x_, int y_, int c) {
        x = x_;
        y = y_;
        cnt = c;
    }
};

int bfs() {
    queue<State> q;
    q.push(State(0, 0, 0));
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        int x = top.x, y = top.y, cnt = top.cnt;
        //printf("%d %d %d\n", y, x, cnt);
        if (x == n-1 && y == n-1) return top.cnt;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //printf("%d %d\n", ny,nx);
            if (check(nx, ny)) {
                hasVisit[ny][nx] = true;
                q.push(State(nx, ny, cnt+1));
            }
        }
    }
    return -1;
}

        
int main() {
    while ((cin >> n) && n) {
        map.clear();
        map.resize(n, vector<bool>(n));
        hasVisit.clear();
        hasVisit.resize(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int b; cin >> b;
                map[i][j] = b;
            }
        }
        int cnt = bfs();
        cout << cnt+1 << endl;
    }
}

