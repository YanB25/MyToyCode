#include <iostream>
using std::cout;
using std::endl;
template <typename T, typename U>
void bar(T lhs, U rhs) {
	cout << "using template" << endl;
}


template <>
void bar<int, int>(int lhs, int rhs) {
	cout << "using specilization" << endl;
}

int main() {
	int i = 0;
	double db = 0;
	bar(db, i);
	bar(i, db);
	bar(i, i);
	return 0;
}
