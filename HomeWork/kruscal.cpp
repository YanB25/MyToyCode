#include <utility>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<vector<int>> weight;
vector<bool> inTree;
vector<int> dist;
int sumWeight = 0;
void kruscal() {
    typedef pair<int, int> iT;
    priority_queue<iT, vector<iT>, greater<iT>> pq; // dist, node
    for (int i = 0; i < n; ++i) pq.push(pair<int, int>(dist[i], i));
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int node = top.second;
        if (inTree[node]) continue;
        inTree[node] = true;
        sumWeight += top.first;
        //cout << top.first << endl;
        for (int i = 0; i < n; ++i) {
            if (weight[node][i] < dist[i]) {
                pq.push(pair<int, int>(weight[node][i], i));
                dist[i] = weight[node][i];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        sumWeight = 0;
        weight.clear();
        weight.resize(n, vector<int>(n));
        inTree.clear();
        inTree.resize(n);
        dist.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int w;
                cin >> w;
                weight[i][j] = w;
            }
        }
        dist.assign(weight.begin()->begin(), weight.begin()->end());
        kruscal();
        cout << sumWeight<< endl;
    }
}


