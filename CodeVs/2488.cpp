#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int from, to, weight;
    Edge(int f, int t, int w) {
        from = f; to = t; weight = w;
    }
};
double sumWeight = 0;
int pn = 0;
double sw;
vector<vector<Edge> > graph;
int n,m;
bool dfs(int node) {
    if (node == n-1) {
        sw += sumWeight;
        pn++;
    }
    for (vector<Edge>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
        int f = it->from, t = it->to, w = it->weight;
        sumWeight += w;
        dfs(t);
        sumWeight -= w;

    }
    return true;
}

int main() {
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int f, t, w;
        cin >> f >> t >> w;
        f--;t--;
        graph[f].push_back(Edge(f, t, w));
    }
    dfs(0);
    printf("%.2lf\n", sw/pn);
}

