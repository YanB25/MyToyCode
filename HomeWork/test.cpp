#include <iostream>
using namespace std;
class Node {
public:
    int entry;
    Node* next;
    Node(){};
    Node(int item, Node* add_on = 0) {
    }
    bool isEmpty() { return false; }
};

int main() {
    Node n;
    cout << sizeof(n) << endl;
    return 0;
}

