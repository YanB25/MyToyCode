#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> graph;
int sum = 0;
vector<int> moneys;
vector<int> color;
bool cycle = false;
void visit(int i) {
    if (color[i] == 1) {
        cycle = true;
    }
    if (color[i] != 0) return;
    color[i] = 1;
    int max = 100;
    for (auto dst : graph[i]) {
        visit(dst);
        if (moneys[dst] > max) max = moneys[dst];
    }
    moneys[i] = max + 1;
    sum += max;
    color[i] = 2;
}
void topological() {
    for (int i = 0; i < graph.size(); ++i) {
        visit(i);
    }
}
int main() {
    #ifdef DEBUG
    freopen("input", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m; 
    graph.resize(n);
    color.resize(n);
    moneys.resize(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from-1].push_back(to-1);
    }
    topological();
    if (cycle) {
        cout << "Poor Xed\n";
    } else {
        cout << sum << endl;
    }
}