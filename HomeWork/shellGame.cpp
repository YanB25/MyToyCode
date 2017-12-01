#include <iostream>
using namespace std;
int arr[7][3] = {{0,1,2},{1,0,2},{1,2,0},{2,1,0},{2,0,1},{0,2,1}};
int main() {
	int rnd;
	int pos;
	cin >> rnd >> pos;
	rnd %= 6;
	int ans = arr[rnd][pos];
	cout << ans << endl;
}
