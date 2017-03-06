#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	freopen("input", "r", stdin);
	int n;
	cin >> n;
	vector<string> arr;
	for (int i = 0; i < n; ++i) {
		string tmp;		
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	int R = 256;
	int len = arr[0].length();
	for (int k = len - 1; k >= 0; --k) {
		vector<int> count(R + 1);
		vector<string> aux(n);
		for (int i = 0; i < n; ++i) {
			count[arr[i][k] + 1]++;
		}
		for (int i = 0; i < R; ++i) {
			count[i + 1] += count[i];
		}
		for (int i = 0; i < n; ++i) {
			aux[count[arr[i][k]]++] = arr[i];
		}
		swap(arr, aux);
	}
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}

