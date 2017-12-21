#include <iostream>
#include <vector>
using namespace std;
vector<bool> hasVisit;
void visit(const vector<vector<int>>& g, int i, vector<int>& result) {
    if (hasVisit[i]) return;
    hasVisit[i] = true;
    cout << "visit " << i << endl;
    for (auto to : g[i]) {
        visit(g, to, result);
    }
    result.push_back(i);

}
vector<int> toposort(const vector<vector<int>>& graph) {
    vector<int> result;
    for (int i = 0; i < graph.size(); ++i) {
        visit(graph, i, result);
    }
    return result;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(n);
    hasVisit.resize(n, false);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }
    auto arr = toposort(graph);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
