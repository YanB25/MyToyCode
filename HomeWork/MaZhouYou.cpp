#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int toIndex(int x, int y) { return y * 8 + x + 1; }
int addx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int addy[] = {1, -1, -1, 1, 2, -2, -2, 2};
int table[8][8];
int order[70];
void print() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            printf("%3d", table[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i <= 64; ++i) {
        printf("%d ", order[i]);
    }
    printf("\n");
}
inline bool isvalid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8 && table[y][x] == 0;
}
int getNextPossibility(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 8; ++i) {
        int nx = x+addx[i];
        int ny = y+addy[i];
        if (isvalid(nx, ny)) ret++;
    }
    return ret;
}
struct NextStep {
    int x;
    int y;
    int distance_;
    int nextPossibility;
    NextStep(int x_, int y_) {
        x = x_;
        y = y_;
        distance_ = abs(x-3) + abs(y-4);
        nextPossibility = getNextPossibility(x, y);
    }
    bool operator<(const NextStep& rhs)const {
        return !(nextPossibility < rhs.nextPossibility || (nextPossibility == rhs.nextPossibility && distance_ > rhs.distance_));
    }
};
bool success =false;
void runTask(int x, int y, int step) {
    if (success) {
        return;
    }
    if (step == 65) {
        //print();
        success = true;
        return;
    }
    priority_queue<NextStep> q;
    for (int i = 0; i < 8; ++i) {
        if (isvalid(x + addx[i], y + addy[i])) {
            q.emplace(x + addx[i], y + addy[i]);
        }
    }
    while (!q.empty()) {
        NextStep nextStep = q.top();
        int nx = nextStep.x; int ny = nextStep.y;
        table[ny][nx] = step;
        order[step] = toIndex(nx, ny);
        runTask(nx, ny, step + 1);
        if (success) return;
        table[ny][nx] = 0;
    }
}

int main() {
    int t;
    //for (int i = 1; i <= 64; ++i) cout << order[i] << " ";//TODO
    while ((cin >> t) && t != -1) {
        success = false;
        memset(table, 0, 8*8 * sizeof(int));
        memset(order, 0, 70 * sizeof(int));
        int x = (t-1) % 8;
        int y = (t-1) / 8; 
        table[y][x] = 1;
        order[1] = toIndex(x, y);
        runTask(x, y, 2);
        int start = -1;
        for (int i = 1; i <= 64; ++i) {
            //cout << order[i] << " ";
            if (order[i] == t) {
                start = i;
                break;
            }
        }
        for (int i = start; i <= 64; ++i) {
            printf("%d ", order[i]);
        }
        for (int i = 1; i < start; ++i) {
            if (i == start - 1) {
                printf("%d\n", order[i]);
            } else {
                printf("%d ", order[i]);
            }
        }

    }
    return 0;
}
