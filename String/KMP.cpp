#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class KMP {
public:
	KMP(const string&);
	bool isMatch(const string&) const;
private:
	int **dfa;
	unsigned PatLength;
};

KMP::KMP(const string& s) {
	PatLength = s.length();
	dfa = new int*[26];
	for (unsigned i = 0; i < 26; ++i) {
		dfa[i] = new int [s.length()];
	}
	for (int i = 0; i < 26; ++i) dfa[i][0] = s[0] == '.' ? 1 : 0;
	dfa[s[0] - 'a'][0] = 1;
	for (int x = 0, j = 1; j < s.length(); ++j) {
		for (int i = 0; i < 26; ++i) {
			dfa[i][j] = dfa[i][x];
		}
			if (s[j] == '.') {
				for (int t = 0; t < 26; ++t) {
					dfa[t][j] = j + 1;
				}
			}else{
				dfa[s[j] - 'a'][j] = j + 1;
			}
		x = dfa[s[j] - 'a'][x];
	}
}

bool KMP::isMatch(const string& txt) const {
	unsigned ipat = 0, itxt = 0;
	for (ipat = 0, itxt = 0; ipat < PatLength && itxt < txt.length(); ++itxt) {
		ipat = dfa[txt[itxt] - 'a'][ipat];
	}
	if (ipat == PatLength) return true;
	return false;
}

int main() {
	freopen("input", "r", stdin);
	string pat("a.a");
	KMP search(pat);
	int n;
	cin >> n;
	string arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (search.isMatch(arr[i])) {
			cout << arr[i] << endl;
		}
	}
	return 0;
}
