
#include <iostream>
#include <cstdio>

using namespace std;

struct Node {
 int number;
 Node *next;
};

class myStack {
private:
 Node *mtop;
 int _size;
public:
 myStack();
 myStack(const myStack &stack);
 myStack(const int *arr, const int _size); // 用数组构造,按顺序压栈
 ~myStack();
 bool empty() const;  // 栈空则返回true
 int top() const; // 返回栈顶元素，如果栈为空则返回0
 bool pop();  
 bool push(int _number); // 请注意push失败的情况，即new失败
 int size() const;

 myStack& operator=(const myStack& stack);
 friend ostream& operator<<(ostream& out, const myStack& stack) {
  Node *t = stack.mtop;
 if (t == NULL) {
  out << "The stack is empty!";
  return out;
 }
 while (t != NULL) {
  out << t->number << ' ';
  t = t->next;
 }
 return out;
 };
};

#include <iostream>

using namespace std;

int main() {
 int a[100];
 int n, m, num;
 cin >> n >> m;
 myStack s1;
 cout << "s1 is empty? " << s1.empty() << endl;
 for (int i = 0; i < n/2; ++i) {
  cin >> num;
  s1.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 myStack s2(s1), s3;
 for (int i = 0;  i < m; ++i) {
  s1.pop();
 }
 cout << "now s1's size is " << s1.size() << endl;
 for (int i = n/2; i < n; ++i) {
  cin >> num;
  s1.push(num); s3.push(num);
 }
 cout << "s1's size is " << s1.size() << endl;
 cout << "s1 is " << s1 << endl;
 cout << "s3 is " << s3 << endl;
 cout << "s2's top is " << s2.top() << endl;
 s2.pop();
 cout << "s2 is "  << s2 << endl;
 cout << "s2 is empty?" << s2.empty() << endl;
 s2 = s1;
 cout << "now s2 is " << s2 << endl;
 cin >> n;
 for (int i = 0; i < n; ++i) {
  cin >> a[i];
 }
 myStack s4(a, n);
 cout << "s4's size is " << s4.size() << endl;
 cout << "s4 is " << s4 << endl;
 s3 = s4; s3.pop();
 cout << "s3 is " << s3 << endl;
 return 0;
 
}

myStack::myStack() : mtop(nullptr), _size(0) { }

myStack::myStack(const int *arr, const int _size) : myStack() {
	for (int i = 0; i < _size; ++i) {
		push(arr[i]);
	}
}
bool myStack::empty() const { return _size == 0; }

int myStack::top() const {
	if (mtop) {
		return mtop->number;
	}
	return 0;
}

int myStack::size() const { return _size; }

bool myStack::push(int _number) {
	Node* node;
	try {
		node = new Node();
	} catch(...) {
		return false;
	}
	
	node->number = _number;
	node->next = mtop;
	mtop = node;
	_size++;
	return true;
}
	
bool myStack::pop() {
	if (mtop == nullptr) {
		return false;
	}
	Node* tmp = mtop->next;
	delete mtop;
	mtop = tmp;
	_size--;
	return true;
}
	
myStack::~myStack() {
	while (!empty()) {
		pop();
	}
}	
	
myStack::myStack(const myStack &stack) {
	Node* cur = stack.mtop;
	Node* cur_node = new Node();
	Node* last_node = nullptr;
	if (cur) {
		cur_node->number = cur->number;
		cur = cur->next;
		mtop = cur_node;
	}
	while (cur) {
		last_node = cur_node;
		cur_node = new Node();
		cur_node->number = cur->number;
		last_node->next = cur_node;
		cur = cur->next;
	}
	cur_node->next = nullptr;
	_size = stack._size;
}
	
myStack& myStack::operator=(const myStack& stack) {
	if (this == &stack) {
		return *this;
	}
	while (!empty()) {
		pop();
		cout << _size << endl;
	}
	Node* cur = stack.mtop;
	Node* cur_node = new Node();
	Node* last_node = nullptr;
	if (cur) {
		cur_node->number = cur->number;
		cur = cur->next;
		mtop = cur_node;
	}
	while (cur) {
		last_node = cur_node;
		cur_node = new Node();
		cur_node->number = cur->number;
		last_node->next = cur_node;
		cur = cur->next;
	}
	cur_node->next = nullptr;
	_size = stack._size;
	return *this;
}
	
	
		
	
	
	
