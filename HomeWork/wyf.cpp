#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// sicily 1135

struct node{
    int row;
    int col;
    int left_fly;
    int step;
    node(int a, int b, int c, int s){
        row = a;
        col = b;
        left_fly = c;
        step = s;
    }
};
const int MAX = 200;
int islake[MAX][MAX]; // 如果是湖，就存1，否则存0（相当于地图）
int visited[MAX][MAX]; // 保存，这个状态是否走过 ！！！！！！！！！！！！！还不清楚
int direct[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int m,n,d;
int min_time = 99999999;
bool isvalid(int row, int col, int fly){
    if (1 <= row && row <= m && 1 <= col && col <= n){
        if (!islake[row][col] && fly > visited[row][col])
            visited[row][col] = fly;
            return true;
    }
    return false;
}


void bfs(){
    queue<node> t;
    t.push(node(1,1,d,0));
    while (!t.empty()){
        node cur_node = t.front();
        t.pop();

        int c_row = cur_node.row;
        int c_col = cur_node.col;
        int c_fly = cur_node.left_fly;
        int c_step = cur_node.step;

        cout << c_row-1 << " " << c_col-1 << " " << c_fly << " " << c_step << endl;
        if (c_row == m && c_col == n){  // 如果已经到达终点
            if (c_step < min_time)
                min_time = c_step;
            continue;
        }


        for (int j = 0; j < 4; j++){// 遍历四种方向
            for (int i = 1; i <= c_fly || i == 1; i++){// 从能走多少步进行遍历
            // 能走的步数：[1步，剩余飞行距离]
            // 其中即使不能飞，也能走一步
            // 如果只走一步，一定是走路而不是飞行
            // 否则（一次走多步）一定是飞行

            // 更新下一步的信息
                int n_row = c_row + direct[j][0]*i;
                int n_col = c_col + direct[j][1]*i; 
                int n_step = c_step + 1;
                int n_fly;
                if (i == 1)
                    n_fly = c_fly;
                else
                    n_fly = c_fly - i;

            // 如果这一步能够走（坐标有效，不是湖，没有走过）
            // 就将这个状态加进队列中
                if (isvalid(n_row, n_col, n_fly)){
                    t.push(node(n_row, n_col, n_fly, n_step));
                }
            }
        }
    }

}


int main(){
    cin >> m >> n >> d;
    for (int i = 0;i < MAX; ++i) {
        for (int j; j < MAX; ++j) {
            visited[i][j] = -1; //MAX D
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            char temp;
            cin >> temp;
            if (temp == 'L')
                islake[i][j] = 1;
            else
                islake[i][j] = 0;
        }
    }
    bfs();
    if (min_time == 99999999)
        cout << "impossible" << endl;
    else
        cout << min_time << endl;
    return 0;
}
