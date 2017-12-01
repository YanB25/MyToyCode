#include <iostream>
using namespace std;
void dfs(int remain_box, int remain_ball, int last_choose, int& cnt) {
    if (remain_box == 0 && remain_ball == 0) {
        cnt++;
    }
    if (remain_box == 0 && !remain_ball == 0) return;
    for (int i = last_choose; i <= remain_ball; ++i) {
        dfs(remain_box -1, remain_ball - i, i, cnt);
    }
}
int main() {
    for (int i = 1; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            int ans = 0;
            dfs(i, j, 0, ans);
            cout << ans << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
