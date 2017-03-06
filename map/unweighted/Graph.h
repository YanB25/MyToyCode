#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <iostream>
using namespace std;
class Graph {
public:
	Graph(istream&);
	const int vec() const;
	const int edge() const;
	const vector<int>& adj(int);
private:
	int V;
	int E;
	vector<vector<int>> _adj;
};

#endif
