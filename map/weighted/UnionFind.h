#ifndef UNION_FIND_H_
#define UNION_FIND_H_
#include <vector>
using std::vector;
class UnionFind {
public:
	UnionFind(int);
	bool isLinked(int x, int y) { return GetId(x) == GetId(y);}
	void link(int , int);
private:
	int GetId(int);
	vector<int> prev;
	vector<int> rank;
};

UnionFind::UnionFind(int n) {
	prev.resize(n);
	rank.resize(n);
	for (int i = 0; i < n; ++i) {
		prev[i] = i;
	}
}

void UnionFind::link(int x, int y) {
	if (isLinked(x, y)) return;
	x = GetId(x);
	y = GetId(y);
	if (rank[x] < rank[y]) {
		prev[x] = y;
	}else{
		prev[y] = x;
		if (rank[x] == rank[y]) {
			rank[x]++;
		}
	}
}

int UnionFind::GetId(int x) {
	if (prev[x] == x) return x;
	return prev[x] = GetId(prev[x]);
}
#endif
