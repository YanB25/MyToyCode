#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
vector<string> map;
int deltaX[256] = {};
int deltaY[256] = {};
int goX[4] = {};
int goY[4] = {};
int x, y;
int px, py;
char dir[] = {'N', 'S', 'W', 'E'};
bool hasVisit[21][21][21][21] = {}; // x, y, px, py
void init() {
    deltaY['N'] = -1;
    deltaY['S'] = 1;
    deltaX['W'] = -1;
    deltaX['E'] = 1;
}
struct State {
    int x, y;
    int px, py;
    int cnt;
    State (int x_, int y_, int px_, int py_, int cnt_ ) {
        x = x_; y = y_; px = px_; py = py_; cnt = cnt_;
    }
};
inline bool canNotStand(int x, int y) {
    return !(map[y][x] == '.');
}
inline bool isFire(int x, int y) {
    return map[y][x] == '!';
}
inline bool canNotMove(int x, int y) {
    return map[y][x] == '#';
}
inline bool checkMeet(int x, int y, int nx, int ny, int px, int py, int npx, int npy) {
    return (nx == npx && ny == npy) || (nx == px && ny == py && npx == x && npy == y);
}
int bfs() {
    State init(x, y, px, py, 0);
    queue<State> q;
    q.push(init);
    while (!q.empty()) {
        State s = q.front(); q.pop();
        if (hasVisit[s.x][s.y][s.px][s.py]) continue;
        hasVisit[s.x][s.y][s.px][s.py] = true;
        if (s.cnt >= 256) return -1;
        for (int i = 0; i < 4; ++i) {
            int x = s.x, y = s.y, px = s.px, py = s.py, cnt = s.cnt;
            int nx = x + deltaX[dir[i]]; int ny = y + deltaY[dir[i]];
            int npx = px + goX[i]; int npy = py + goY[i];                       
            if (canNotStand(nx, ny))continue;
            if (isFire(npx, npy)) continue;
            if (canNotMove(npx, npy)) {
                npx = px; npy = py;
            }
            if (checkMeet(x, y, nx, ny, px, py, npx, npy)) {
                return cnt + 1;
            }
            q.push(State(nx, ny, npx, npy, cnt + 1));
            #ifdef DEBUG
            printf("%d %d %d %d %d\n", nx, ny, npx, npy, cnt + 1);
            #endif
        }
    }
    return -1;
}
int main() {
    #ifdef DEBUG
    freopen("input", "r", stdin);
    #endif
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        map.push_back(s);
    }
    string d; cin >> d;
    init();
    for (int i = 0; i < 4; ++i) {
        goX[i] = deltaX[d[i]];
        goY[i] = deltaY[d[i]];
    }
    #ifdef DEBUG
    //cout << "info\n";
    //for (int i = 0; i < 4; ++i) {
    //    cout << goX[i] << " " << goY[i] << endl;
    //}
    #endif
    for (int i = 0; i < map.size(); ++i) {
        int w = map[i].find('P');
        int g = map[i].find('H');
        if (w != string::npos) {
            y = i; x = w;
            map[y][x] = '.';
        }
        if (g != string::npos) {
            py = i;
            px = g;
            map[py][px] = '.';
        }
    }
    int cnt = bfs();
    if (cnt == -1) {
        cout << "Impossible\n";
    } else {
        cout << cnt << endl;
    }
}