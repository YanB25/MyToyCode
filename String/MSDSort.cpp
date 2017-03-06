#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int R = 256;
const int M = 15;
int charAt(const string& s, int i) {
	if (i < s.length()) {
		return s[i] + 1;
	}
	return 0;
}

void InsertSort(vector<string>& arr, int beg, int end, int d) {
	if (beg >= end) return;
	for (int i = beg; i <= end; ++i) {
		for (int j = i; j > beg && arr[j].substr(d) < arr[j - 1].substr(d); --j) {
			swap(arr[j], arr[j - 1]);
		}
	}
}

void sort(vector<string>& arr, int beg, int end, int d) {
	if (end - beg <= 15) { InsertSort(arr, beg, end, d); return;}
	vector<int> count(R + 5);
	vector<string> tmp(end - beg + 1);
	for (int i = beg; i <= end; ++i) {
		count[charAt(arr[i], d) + 1]++;
	}
	for (int i = 0; i < R + 1; ++i) {
		count[i + 1] += count[i];
	}
	for (int i = beg; i <= end; ++i) {
		tmp[count[charAt(arr[i], d)]++] = arr[i];
	}
	for (int i = beg; i <= end; ++i) {
		arr[i] = tmp[i - beg];
	}
	for (int i = 0; i < R; ++i) {
		sort(arr ,beg + count[i], beg + count[i + 1] - 1, d + 1);
	}
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
	
