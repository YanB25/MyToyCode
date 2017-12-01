#include <iostream>
#include <regex>
#include <string>
using namespace std;
int main() {
    string txt = "p = (1, 3)(2, 5)(2, 3)";
    string pattern = "[a-zA-Z]+";
    smatch m;
    regex re(pattern);
    regex_search(txt, m, re);
    for (int i = 0; i < m.size(); ++i) {
        cout << m[i] << endl;
    }
    return 0;
}
