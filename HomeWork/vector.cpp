#include <iostream>
template <int n>
class vector {
public:
	vector();
	vector(double[n]);
	vector<const vector&);
	vector operator+(const vector&) const;
	vector operator-(const vector&) const;
	vector operator-() const;
	int operator*(const vector&) const;
	vector operator*(int) const;
	
private:
	double entries[n];
};
int main() {
	return 0;
}
