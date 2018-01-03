#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::queue;
int n, m;
int src = 1;
int dst;
struct Edge {
    int from;
    int to;
    int weight;
    Edge (int f, int t, int w) {
        from = f; to = t; weight = w;
    }
};
vector<vector<Edge>> graph;
vector<int> distance;
void spfa() {
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (const auto& edge : graph[node]) {
            int f = edge.from, t = edge.to, w = edge.weight;
            if (distance[t] > distance[f] + w) {
                distance[t] = distance[f] + w;
                q.push(t);
            }
        }
    }
}

        
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        dst = n;
        graph.clear();
        graph.resize(n + 4);
        distance.clear();
        distance.resize(n + 4, INT_MAX/10);
        for (int i = 0; i < m; ++i) {
            int f, t ,w;
            cin >> f >> t >> w;
            graph[f].push_back(Edge(f, t, w));
            graph[t].push_back(Edge(t, f, w));
        }
        distance[src] = 0;
        spfa();
        cout << (distance[dst] == INT_MAX / 10 ? -1 : distance[dst]) << endl;
    }
}



