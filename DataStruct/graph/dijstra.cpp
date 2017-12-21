#include <climits>
#include <vector>
#include <iostream>
#include <set>
#include <utility>
using std::set;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) {
        to = t;
        weight = w;
    }
};
vector<int> dijkstra(const vector<vector<Edge>>& graph, int src) {
    vector<int> min_dist(graph.size(), INT_MAX);
    min_dist[src] = 0;
    set<pair<int, int>> active_node;
    active_node.insert({0, src});
    while (!active_node.empty()) {
        int where = active_node.begin()->second;
        active_node.erase(active_node.begin());
        for (auto eg : graph[where]) {
            if (min_dist[eg.to] > min_dist[where] + eg.weight) {
                active_node.erase({min_dist[eg.to], eg.to});
                min_dist[eg.to] = min_dist[where] + eg.weight;
                active_node.insert({min_dist[eg.to], eg.to});
            }
        }
    }
    return min_dist;
}
int main() {
    int n;
    cin >> n;
    vector<vector<Edge>> graph(n);
    int from, to, weight;
    for (int i = 0; i < n; ++i) {
        cin >> from >> to >> weight;
        graph[from].push_back(Edge(to, weight));
    }
    auto results = dijkstra(graph, 6);
    for (int i = 0; i < results.size(); ++i) {
        cout << i << ": " << results[i] << endl;
    }
}