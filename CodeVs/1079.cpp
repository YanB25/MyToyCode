#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cctype>
using namespace std;
int src;
struct Edge {
    int from;
    int to;
    int weight;
    Edge (int f, int t, int w) {
        from = f;
        to = t;
        weight = w;
    }
};
int toIndex(int input) {
    if (islower(input)) return input - 'a';
    return input - 'A' + 'z' - 'a' + 1;
}
vector<vector<Edge> > graph;
vector<int> dist;
void spfa() {
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (vector<Edge>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
            int t = it->to;
            int w = it->weight;
            int f = node;
            if (dist[t] >= dist[f] + w) {
                dist[t] = dist[f] + w;
                q.push(t);
            }
        }
    }
}

int main() {
    graph.resize(26*2+1);
    dist.resize(26*2+1, INT_MAX/10);
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        int f = toIndex(a);
        int t = toIndex(b);
        graph[f].push_back(Edge(f, t, w));
        graph[t].push_back(Edge(t, f, w));
        if (a == 'Z') src = f;
        if (b == 'Z') src = t;
    }
    dist[src] = 0;
    spfa();
    int min = dist[toIndex('A')];
    int minInd = toIndex('A');
    for (int i = toIndex('A'); i < toIndex('Z'); ++i) {
        if (dist[i] < min) {
            min = dist[i];
            minInd = i;
        }
    }
    cout << char(minInd + 'A' - 'z' + 'a' - 1) << " " << min << endl;


}
