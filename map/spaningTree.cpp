#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class DisjointSet{
public:
    DisjointSet(int n) : size_(n) {
        prev.resize(n);
        for (int i = 0; i < n; ++i) {
            prev[i] = i;
        }
    }
    bool isLinked(int lhs, int rhs) {
        return getID(lhs) == getID(rhs);
    }

    int getID(int i) {
        while (i != prev[i]) {
            i = prev[i];
        }
        return i;
    }

    void connect(int lhs, int rhs) {
        lhs = getID(lhs); rhs = getID(rhs);
        prev[lhs] = rhs;
    }

    vector<int> prev;
    int size_;
};

struct Edge {
    int one;
    int other;
    int weight;
    Edge(int on, int o, int w) {
        one = on;
        other = o;
        weight = w;
    }
    int One() { return one; }
    int Other(int i) { return i == one? other : one; }
    bool operator<(const Edge& rhs) { return weight > rhs.weight; } //TODO
};

int main() {
    int sum_weight = 0;
    int v, e;
    cin >> v >> e;
    DisjointSet djs(v);
    int one, other, weight;
    vector<Edge> edges; 
    while (e--) {
        cin >> one >> other >> weight;
        edges.emplace_back(one, other, weight);
    }
    sort(edges.begin(), edges.end());
    vector<Edge> tmp(edges.begin(), edges.end());
    while (!tmp.empty()) {
        auto edge = tmp.back(); tmp.pop_back();
        int one = edge.One(); int other = edge.Other(one);
        if (djs.isLinked(one, other)) continue;
        djs.connect(one, other);
        cout << one << " " << other << " " << edge.weight << endl;
        //djs.print();
        sum_weight += edge.weight;
    }
    cout << endl;
    cout << sum_weight << endl;
    return 0;
}

