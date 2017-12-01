#include<iostream>  
#include <stdlib.h>  
#include <iomanip>  
  
using namespace std;  
  
//马周游的棋盘，注意使用的时候是从下表为1开始  
int board[100][100];  
  
int fx[]= {2,1,-1,-2,-2,-1,1,2};  
int fy[]= {-1,-2,-2,-1,1,2,2,1};  
  
int n; //棋盘大小  
  
//参数x,y 表示棋盘的位置  
//检测(x,y) 对应位置在棋盘中是否合法  
bool check(int x,int y)  
{  
    if(x<1 || y<1 || x>n || y>n || board[x][y] != 0)  
        return false;  
    return true;  
}  
  
//输出结果  
void outputResult(int n)  
{  
    for(int i=1; i<=n; i++)  
    {  
        cout<<endl<<endl;  
        for(int j=1; j<=n; j++)  
        {  
            cout<<setw(3)<<board[i][j]<<" ";  
        }  
    }  
    cout<<endl<<endl;  
}  
  
void runTable(int a,int b,int number)  
{  
    if(number == n*n) //已经走完棋盘中所有的点  
    {  
        outputResult(n); //输出  
        exit(1);  
    }  
  
    for(int i=0; i<8; i++) //表示每一个格都有八种走法  
    {  
        if(check(a + fx[i],b + fy[i]))  
        {  
            int x = a + fx[i];  
            int y = b + fy[i];  
  
            board[x][y] = number+1; //走到下一个位置，设置其序号为 number+1  
  
            runTable(x, y,number+1);  
            board[x][y] = 0;//回溯  
        }  
    }  
}  
  
//递归走法  
void horseRun(int x,int y)  
{  
    int number = 1;  
    board[x][y] = number; //首先确定起始位置这个格是序号为1  
    runTable(x, y,number);  
}  
  
int main()  
{  
    cout<<"输入棋盘大小n:";  
    cin>>n;  
  
    int x,y;  
    cout<<"输入马周游起始位置x(1~n),y(1~n):";  
    cin>>x>>y;  
  
    horseRun(x,y);  
    return 0;  
}  
