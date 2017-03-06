#ifndef DIR_EDGE_H_
#define DIR_EDGE_H_
#include <cstdio>
class DirEdge {
public:
	DirEdge();
	DirEdge(int from, int to, double weight); 
	const int From() const { return _from;}
	const int To() const { return _to;}
	const double GetWeight() const { return _weight; }
	bool operator<(const DirEdge& rhs) const { return rhs.GetWeight() < GetWeight(); }
private:
	int _from;
	int _to;
	double _weight;
};

DirEdge::DirEdge(){
	printf("1");
	_from = -1;
	_to = -1;
	_weight = 0;
}

DirEdge::DirEdge(int from, int to, double weight) {
	printf("2");
	_from = from;
	_to = to;
	_weight = weight;
}
#endif
