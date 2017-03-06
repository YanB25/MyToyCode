#ifndef DIR_GRAPH_H_
#define DIR_GRAPH_H_
#include <vector>
#include <iostream>
using namespace std;
class DirGraph {
public:
	const int V()const {return _v;}
	const int E()const {return _e;}
	DirGraph(istream& is);
	DirGraph(int);
	DirGraph reverse()const;
	const vector<int>& adj(int x) const { return _adj[x];}
	void InsertEdge(int, int);
private:
	int _v;
	int _e;
	vector<vector<int>> _adj;
};
#endif
