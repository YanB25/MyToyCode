#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <climits>
using namespace std;
int m, n;
int cost;
vector<string> map;
vector<pair<int, int> > gates;
vector<vector<int> > hasVisit;
typedef pair<int, int> Point;
int stepX[] = { 0, 0, -1, 1};
int stepY[] = {-1, 1, 0, 0};
int posX, posY;
struct State {
    int x, y;
    int money;
    State(int x_, int y_, int m) {
        x = x_;
        y = y_;
        money = m;
    }
};
bool isValid(int x, int y) {
    return y >= 0 && x >= 0 && y < m && x < n && map[y][x] != '#';
}
bool isGate(int x, int y) {
    return map[y][x] == 'P';
}
bool isCost(int x, int y) {
    return map[y][x] == '*';
}
bool isArrive(int x, int y) {
    return map[y][x] == 'C';
}
int solve() {
    queue<State> q;
    q.push(State(posX, posY, 0));
    while (!q.empty()) {
        State s = q.front(); q.pop();
        int x = s.x, y = s.y, m = s.money;
        //printf("%d %d %d\n", x, y, m);
        if (isArrive(x, y)) return m;
        if (m >= hasVisit[y][x]) continue;
        hasVisit[y][x] = m;
        for (int i = 0; i < 4; ++i) {
            int nx = x + stepX[i];
            int ny = y + stepY[i];
            if (!isValid(nx, ny)) continue;
            if (isGate(nx, ny)) {
                for (vector<Point>::iterator it = gates.begin(); it != gates.end(); ++it) {
                    q.push(State(it->first, it->second, m));
                }
            } else if (isCost(nx, ny)) {
                q.push(State(nx, ny, m + cost));
            } else {
                q.push(State(nx, ny, m));
            }
        }
    }
    return -1;
}

int main() {
    cin >> m >> n;
    cin >> cost;
    hasVisit.resize(m, vector<int>(n, INT_MAX / 10));
    for (int i = 0; i < m; ++i) {
        string line;
        cin >> line;
        map.push_back(line);
        int f = line.find('Y');
        if (f != string::npos) {
            posY = i;
            posX = f;
            //cout << "p " << posX << " " << posY << endl;
        }
        for (string::iterator it = line.begin(); it != line.end(); ++it) {
            if (*it == 'P') {
                gates.push_back(Point(it - line.begin(), i));
            }
        }
    }
    int res = solve();
    if (res == -1) {
        cout << "screw you!\n";
    } else {
        cout << res << endl;
    }
}

