#include <iostream>
#include <vector>
using namespace std;
int n, m;
int cnt = 0;
vector<bool> hasVisit;
vector<vector<int>> graph;
bool visit(int i) {
    if (hasVisit[i]) return false;
    hasVisit[i] = true;
    for (auto dst : graph[i]) {
        visit(dst);
    }
    return true;
}

void dfs() {
    for (int i = 1; i <= n; ++i) {
        if (visit(i)) {
            cnt++;
        }
    }
}
int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    hasVisit.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int f, t;
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    dfs();
    cout << cnt << endl;
}



