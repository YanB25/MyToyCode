#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string target;
vector<string> map;
int m;
bool check(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < m;
}
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool func(int x, int y, int index) {
    if (map[y][x] != target[index]) return false;
    if (index == target.size()-1) return true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check(nx, ny)) {
            if (func(nx, ny, index+1)) return true;
        }
    }
    return false;
}

    
int main() {
    int t;
    cin >> t;
end:
    while (t--) {
        map.clear();
        string input;
        cin >> input >> target;
        m = sqrt(input.size());
        auto it = input.begin();
        while (it != input.end()) {
            map.push_back(string(it, it + m));
            it += m;
        }
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < m; ++x) {
                if (func(x, y, 0)) {
                    cout << "true\n";
                    goto end;
                }
            }
        }
        cout << "false\n";
    }
}

