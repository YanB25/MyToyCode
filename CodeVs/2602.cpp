#include <queue>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct Edge {
    int from;
    int to;
    double weight;
    Edge(int f, int t, double w) {
        from = f;
        to = t;
        weight =w ;
    }
};
int scrNode, dstNode;
typedef pair<int, int> Point;
vector<Point> points;
vector<vector<Edge> > graph;
vector<double> dist;
double calDist(const Point& p1, const Point& p2) {
    double x = p1.first, y = p1.second;
    double nx = p2.first, ny = p2.second;
    return sqrt(1.0*(x-nx)*(x-nx) + 1.0*(y-ny)*(y-ny));
}
int n,m ;
void spfa() {
    queue<int> q;
    q.push(scrNode);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (vector<Edge>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
            int f = it->from, t = it->to;
            double w = it->weight;
            if (dist[t] > dist[f] + w) {
                dist[t] = dist[f] + w;
                q.push(t);
            }
        }
    }
}
int main() {
    cin >> n;
    graph.resize(n);
    dist.resize(n, INT_MAX/10);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int f, t;
        cin >> f >> t;
        f--;t--;
        double d = calDist(points[f], points[t]);
        graph[f].push_back(Edge(f, t, d));
        graph[t].push_back(Edge(t, f, d));
    }
    cin >> scrNode >> dstNode;
    scrNode--;dstNode--;
    dist[scrNode] = 0;
    spfa();
    printf("%.2lf\n", dist[dstNode]);
}
