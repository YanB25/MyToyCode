#include <cctype>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int weight = 10;
        int sum = 0;
        for (char c : s) {
            if (weight < 2) break;
            if (isdigit(c)) {
                sum += weight * (c - '0');
                weight--;
            }
        }
        int check = (sum / 11 + 1) * 11 - sum;
        char last = check < 10 ? check + '0': 'X';
        cout << s << "-" << last << endl;
    }
    return 0;
}


