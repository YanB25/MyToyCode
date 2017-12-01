#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct Data {
    char head;
    string pre;
    string in;
    Data(char h, string p, string i) {
        head = h;
        pre = p;
        in = i;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pre;
        string in;
        cin >> pre >> in;
        Data first(pre[0], pre, in);
        queue<Data> q;
        q.push(first);
        while (!q.empty()) {
            Data top = q.front(); q.pop();
            cout << top.head;
            string& pre = top.pre;
            string& in = top.in;
            int pos = top.in.find(top.head);
            string leftIn = in.substr(0, pos);
            string rightIn = in.substr(pos + 1);
            //cout << "leftIn: " << leftIn << " rightIn: " << rightIn << endl;
            int lz = leftIn.size();
            string leftPre = pre.substr(1, lz);
            string rightPre = pre.substr(1 + lz);
            //cout << "leftPre: " << leftPre << " rightPre" << rightPre << endl;
            Data left(leftPre[0], leftPre, leftIn);
            Data right(rightPre[0], rightPre, rightIn);
            if (leftPre != "" && leftIn != "")
                q.push(left);
            if (rightPre != "" && rightIn != "")
                q.push(right);
        }
        cout << endl;
    }
}
             

