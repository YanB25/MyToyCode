#include <stack>
#include <queue>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int n, m;
int src, dst;
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
vector<int> father;
vector<int> dist;
vector<int> visitTime;
bool relax(const Edge& edge) {
    int to = edge.to, from = edge.from, weight = edge.weight;
    if (dist[from] + weight < dist[to]) {
        dist[to] = dist[from] + weight;
        father[to] = from;
        return true;
    }
    return false;
}
bool spfa() {
    queue<int> q;
    q.push(src - 1);
    while (!q.empty()) {
        int top = q.front(); q.pop();
        for (auto edge : graph[top]) {
            if (relax(edge)) {
                q.push(edge.to);
                visitTime[edge.to]++;
                if (visitTime[edge.to] >= n)
                    return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> n >> m >> src >> dst;
    graph.resize(n);
    father.resize(n, -1);
    dist.resize(n, INT_MAX / 100);
    visitTime.resize(n, 0);
    dist[src - 1] = 0;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
   // cout << "ok\n";
        graph[from - 1].push_back(Edge(from - 1, to - 1, weight));
        graph[to - 1].push_back(Edge(to - 1, from - 1, weight));
    }
    for (auto v : graph) {
        for (auto i : v) {
            cout << i.from << " " << i .to << " ";
        }
        cout << endl;
    }
    spfa();
    if (spfa()) {
        for (int i = 0 ; i < dist.size(); ++i) {
            cout << i << " " << dist[i] << endl;
        }
    }
    stack<int> s;
    s.push(dst);
    int f = dst;
    while (father[f] != -1) {
        s.push(father[f]);
        f = father[f];
    }   
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}