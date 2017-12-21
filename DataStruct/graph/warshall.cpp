#include <climits>
#include <iostream>
#include <vector>
using namespace std;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) {
        to = t;
        weight = w;
    }
};
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dist;
    for (int i = 0; i < n; ++i) dist.push_back(vector<int>(n, INT_MAX / 5));
    int from, to, weight;
    for (int i = 0; i < n; ++i) {
        cin >> from >> to >> weight;
        dist[from][to] = weight;
    }
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    for (int k = 0; k < n; ++k) {
        for (int b = 0; b < n; ++b) {
            for (int e = 0; e < n; ++e) {
                if (dist[b][k] + dist[k][e] < dist[b][e]) {
                    dist[b][e] = dist[b][k] + dist[k][e];
                }
            }
        }
    }
    for (auto v: dist) {
        for (auto item : v) {
            cout << (item >= 10000 ? -1 : item) << " ";
        }
        cout << endl;
    }
    cout << endl;
}