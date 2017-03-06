#ifndef EDGE_H_
#define EDGE_H_

class Edge {
public:
	Edge(int _x, int _y, double _w):x(_x), y(_y), weight(_w){};
	Edge():x(-1), y(-1), weight(0){};
	int either() const { return x; }
	int other(int) const;
	bool operator<(const Edge& rhs) const { return rhs.weight < weight; }
	const double GetWeight() const { return weight; }
private:
	int x;
	int y;
	double weight;
};

int Edge::other(int t) const {
	if (t == x) return y;
	else if (t == y) return x;
	else throw;
}
#endif
