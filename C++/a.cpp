#include <iostream>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = 0;
        while (x != 0 || y != 0) {
            cout << x << " " << y;
            if ((x&1) != (y&1)) {
                ret ++;
                    cout << "yes";
            }
            x>>=1;
            y>>=1;
            cout << endl;
        }
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.hammingDistance(1, 4) << endl;
}
