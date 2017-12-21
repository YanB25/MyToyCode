#include <climits>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int to;
    int weight;
    int from;
    Edge(int f, int t, int w) {
        to = t;
        weight = w;
        from = f;
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> prev(n, -1);
    vector<Edge> edges;
    vector<int> dist(n, INT_MAX / 100);
    int src = 0;
    dist[src] = 0;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back(Edge(from, to ,weight));
    }
    for (int i = 1; i <= n-1; ++i) {
        for (auto& edge : edges) {
            if (dist[edge.from] + edge.weight < dist[edge.to]){
                cout << "relax " << edge.from << " " << edge.to << " to " << dist[edge.from] + edge.weight << endl;
                prev[edge.to] = edge.from;
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }
    for (auto& edge : edges) {
        if (dist[edge.from] + edge.weight < dist[edge.to]) {
            cerr << "error!! negetive cycle\n";
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    for (int i = 0; i < n; ++i) {
        cout << prev[i] << " ";
    }
    cout << endl;
}
