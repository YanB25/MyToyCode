#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Edge {
    Edge(int e, int o, int w) {
        either = e;
        other = o;
        weight = w;
    }
    int either;
    int other;
    int weight;
    int Other(int i) { return i == either ? other : either; }
};

struct Node {
    int id = -1;
    int dist = 1e5;
    bool hasVisit = false;
    int prev = -1;
    bool operator<(const Node& rhs) { return dist < rhs.dist; }
};

int main() {
    int v, e;
    cin >> v >> e;
    int weight, either, other;
    vector<vector<Edge>> adj; adj.resize(v);
    while (e--) {
        cin >> either >> other >> weight;
        adj[either].emplace_back(either, other, weight);
        adj[other].emplace_back(either, other, weight);
    }

    vector<Node> nodes; nodes.resize(v);
    for (int i = 0; i < v; ++i) nodes[i].id = i;
    nodes[0].dist = 0;

    vector<Node> priority_queue;
    priority_queue.push_back(nodes[0]);

    while (!priority_queue.empty()) {
        pop_heap(priority_queue.begin(), priority_queue.end()); auto min_node = priority_queue.back(); priority_queue.pop_back();
        int from = min_node.id;
        for (auto edge : adj[from]) {
            int to = edge.Other(from);
            int weight = edge.weight;
            int old_weight = nodes[to].dist;
            int new_weight = nodes[from].dist + weight;
            if (new_weight < old_weight) {
                nodes[to].dist = new_weight;
                nodes[to].prev = from;
                priority_queue.push_back(nodes[to]); push_heap(priority_queue.begin(), priority_queue.end());
            }
        }
    }
    for (int i = 0; i < v; ++i) {
        cout << i << " : " << nodes[i].dist << endl;
    }
    
    return 0;
}
                
