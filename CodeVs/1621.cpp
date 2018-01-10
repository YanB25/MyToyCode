#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <deque>
using namespace std;
struct Milk{
    int sum;
    int price;
    Milk(int s, int p) {
        sum = s;
        price = p;
    }
    bool operator>(const Milk& rhs) const {
        return price > rhs.price;
    }
};
int main() {
    int n, m;
    int money = 0;
    cin >> n >> m;
    priority_queue<Milk, std::vector<Milk>, std::greater<Milk> > q;
    for (int i = 0; i < m; ++i) {
        int p, s;
        cin >> p >> s;
        q.push(Milk(s, p));
    }
    while (n != 0) {
        Milk milk = q.top(); q.pop();
        int milkSum = milk.sum;
        int milkPrice = milk.price;
        if (milkSum >= n) {
            money += milkPrice * n;
            n = 0;
        } else {
            money += milkPrice * milkSum;
            n -= milkSum;
        }
    }
    cout << money << endl;
}


