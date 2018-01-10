#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int step = 0;
bool isRev(const string& s) {
    int i = 0, j = s.size() -1;
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int toNum(char c) {
    if (isdigit(c)) return c - '0';
    if (islower(c)) return c - 'a' + 10;
    return c - 'A' + 10;
}
string add(const string& lhs, const string& rhs, int n) {
    string res(lhs.size(), '\0');
    bool carry = false;
    bool addHead = false;
    for (int i = lhs.size(); i >= 0; --i) {
        int tmp = toNum(lhs[i]) + toNum(rhs[i]) + carry; 
        carry = false;
        if (tmp >= n) {
            tmp %= n;
            if (i > 0) {
                carry = true;
            } else {
                addHead = true;
            }
        }
        if (n != 16) {
            res[i] = '0' + tmp;
        } else {
            res[i] = tmp >= 10 ? tmp - 10 + 'a' : '0' + tmp;
        }
        if (addHead) {
            res = "1" + res;
            addHead = false;
        }
    }
    return res;
} 
int main() {
    int n;
    string num;
    cin >> n;
    cin >> num;
    while (!isRev(num)) {
        string rev = num;
        reverse(rev.begin(), rev.end());
        num = add(num, rev, n);
        //cout << num << endl;
        step++;
        if (step > 30) {
            step = -1;
            break;
        }
    }
    if (step == -1) {
        cout << "impossible!\n";
    } else {
        printf("STEP=%d\n", step);
    }
}

