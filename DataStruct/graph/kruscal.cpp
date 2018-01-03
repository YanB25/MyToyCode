#include <functional>
#include <utility>
#include <climits>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int from;
    int to;
    int weight;
    Edge(int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};
vector<vector<Edge>> graph;
vector<bool> inTree;
int sumWeight = 0;
vector<int> dist;
bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs < rhs;
}
void kruscal() {
    typedef pair<int, int> item_t;
    priority_queue<item_t, vector<item_t>, greater<item_t>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int node = top.second;
        if (inTree[node]) continue;
        cout << node << " " << dist[node] << endl;
        inTree[node] = true;
        sumWeight += dist[node];
        for (auto edge : graph[node]) {
            int from = node;
            int to = edge.to;
            int weight = edge.weight;
            if (dist[to] > weight) {
                cout << "relax " << from << " " << to << endl;
                dist[to] =  weight;
                pq.push({dist[to], to});
            }
        }
    }

}
int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    inTree.resize(n);
    dist.resize(n, INT_MAX / 100);
    dist[0] = 0;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(from, to, weight));
        graph[to].push_back(Edge(to, from, weight));
    }
    kruscal();
    cout << sumWeight << endl;
}