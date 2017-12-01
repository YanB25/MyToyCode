#include <ctime>
#include <iostream>
using namespace std;
long long frac(int n) {
    long long ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret *= i;
    }
    return ret;
}
long long r_frac(int n) {
    if (n == 0)
        return 1;
    return n * frac(n - 1);
}
int main() {
    cout << 1 / 2 * 0.5 << endl;

    return 0;
}
