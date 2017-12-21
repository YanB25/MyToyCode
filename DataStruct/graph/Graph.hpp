#include "directNode.hpp"
#include <iostream>
using std::cin;
class Graph {
public:
    void readData();
private:
    vector<directNode> nodes;
    int n;
};
void Graph::readData() {
    cin >> n;
    nodes.resize(n);
    int from, to;
    while (cin >> from >> to) {
        nodes[from].linkto(to);
    }
}