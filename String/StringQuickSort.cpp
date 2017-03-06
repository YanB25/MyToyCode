#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int charAt(const string& s, int i) {
	if (i < s.length()) return s[i] + 1;
	return 0;
}

void sort(vector<string>& arr, int beg, int end, int d) {
	if (beg >= end) return;
	int lt = beg, gt = end;
	int i = beg + 1, pivot = charAt(arr[beg], d);
	while (i <= gt) {
		int cmp = charAt(arr[i], d);
		if (cmp < pivot) swap(arr[lt++], arr[i++]);
		else if (cmp > pivot) swap(arr[gt--], arr[i]);
		else i++;
	}
	sort(arr, beg, lt - 1, d);
	sort(arr, gt + 1, end, d);
	if (pivot > 0) sort(arr, lt, gt, d + 1); 
}

int main() {
	freopen("input", "r", stdin);
	int n;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, 0, n - 1, 0);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}
	
