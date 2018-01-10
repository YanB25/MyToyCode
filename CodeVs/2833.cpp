#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> in;
set<int> ready;
set<int> hasVisit;
vector<vector<int> > graph;
int n, m;
void func() {
    while (!ready.empty()){
        int node = *(ready.begin()); ready.erase(ready.begin());
        hasVisit.insert(node);
        for (vector<int>::iterator it = graph[node].begin(); it != graph[node].end(); ++it) {
            in[*it]--;
            if (in[*it] == 0) {
                ready.insert(*it);
            }
        }
    }
}


int main() {
    cin >> n >> m;
    in.resize(n);
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int f, t;
        cin >> f >> t;
        f--;t--;
        in[t]++;
        graph[f].push_back(t);
    }
    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == 0) {
            ready.insert(i);
        }
    }
    func();
    int diff = n - hasVisit.size();
    if (diff) {
        cout << "T_T\n" << diff << endl;
    } else {
        cout << "o(∩_∩)o\n";
    }
}

