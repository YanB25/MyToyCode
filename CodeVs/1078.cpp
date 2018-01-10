#include <functional>
#include <iostream>
#include <queue>
#include <climits>
#include <cstdio>
#include <vector>
using namespace std;
int n;
int weight[105][105] = {};
vector<int> dist;
vector<bool> inTree;
int sumWeight = 0;
bool cmp(int l, int r) { return l > r; }
void kruscal() {
    priority_queue<pair<int, int>, std::deque<pair<int, int> >, std::greater<pair<int, int> > > q;
    q.push(pair<int, int>(0, 0));
    while (!q.empty()) {
        pair<int, int> p = q.top(); q.pop();
        int node = p.second;
        if (inTree[node]) continue;
        inTree[node] = true;
        sumWeight += p.first;
        for (int i = 0; i < n; ++i) {
            if (!inTree[i] && weight[node][i] < dist[i]) {
                dist[i] = weight[node][i];
                q.push(pair<int, int>(dist[i], i));
                //cout << i << " " << dist[i] << endl;
            }
        }
    }
}
int main() {
    cin >> n;
    dist.resize(n, INT_MAX / 10);
    inTree.resize(n);
    dist[0] = 0;
    for (int i = 0; i < n ;++i) {
        for (int j = 0; j < n; ++j) {
            int t; cin >> t;
            weight[i][j]  = t;
        }
    }
    kruscal();
    cout << sumWeight << endl;
}
