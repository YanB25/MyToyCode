#include <iostream>
#include <cassert>
int new_t = 0;
int delete_t = 0;
using namespace std;
struct node {
  int ele;
  node* left;
  node* right;
  node(int e):left(0), right(0){
    ele = e;
  }
};
class BinaryTree {
  private:
    node* root;
    void MemoryDelete(node* p);
    static void BuildTree(const node* Source_Root, node* &Target_Root);
    static void BuildTree(const int* arr,int len, node* &root);
    static void preorder(const node* p);
  public:
    BinaryTree();
    BinaryTree(const BinaryTree&);
    BinaryTree(const int* arr, int len);
    void ResetTree(const int* arr, int len);
    ~BinaryTree();
    void clear();
    void insert(int ele);
    void Delete(int ele);
    void print();
};

node* _insert(node* nod, int ele) {
	if (nod == nullptr) { new_t ++; return new node(ele);}
	if (nod->ele > ele) nod->left = _insert(nod->left, ele);
	if (nod->ele < ele) nod->right = _insert(nod->right, ele);
	return nod;
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

node* _copy(node** x, node* rhs) {
	if (rhs == nullptr) *x = rhs;
	else {new_t++; *x = new node(rhs->ele);}
	if(rhs) {
		_copy(&((*x)->left), rhs->left);
		_copy(&((*x)->right), rhs->right);
	}
}

BinaryTree::BinaryTree(const BinaryTree& rhs) {
	root = nullptr;
	_copy(&root, rhs.root);
}

BinaryTree::BinaryTree(const int* arr, int len) {
	//cout << "arr" << endl;
	root = nullptr;
	for (int i = 0; i < len; ++i) { 
		//cout << "insert " << arr[i] << endl;
		insert(arr[i]);
	}
}

	

void BinaryTree::insert(int ele) {
	root = _insert(root, ele);
}

node* _deleteMax(node* nod) {
	assert(nod != nullptr);
	if (nod->right == nullptr) {
		node* ret = nod->left;
		delete_t++;
		delete nod;
		return ret;
	}
	nod->right = _deleteMax(nod->right);
	return nod;
}

node* _max(node* x) {
	assert(x != nullptr);
	while (x->right != nullptr) {
		x = x->right;
	}
	return x;
}

node* _delete(node* x, int ele) {
	if (x == nullptr) return x;
	if (x->ele > ele) {
		x->left = _delete(x->left, ele);
	} else if (x->ele < ele) {
		x->right = _delete(x->right, ele);
	} else if (x->ele == ele){
		if (x->left){
			node* target = _max(x->left);
			
			node* copy_target = new node(target->ele);
			new_t++;
			copy_target->left = target->left;
			copy_target->right = target->right;
			
			copy_target->right = x->right;
			copy_target->left = _deleteMax(x->left);
			delete_t++;
			delete x;
			target = nullptr;
			return copy_target;
		}
		else if (x->left == nullptr)
			return x->right;
	}
	return x;
}
void BinaryTree::Delete(int ele) {
	root = _delete(root, ele);
}

void _clear_aux(node* x) {
	if (x == nullptr) return;
	if (x->left) _clear_aux(x->left);
	if (x->right) _clear_aux(x->right);
	//cout << "delete:" << x->ele << endl;
	delete_t++;
	delete x;
}

void BinaryTree::clear() {
	_clear_aux(root);
	root = nullptr;
}

void _print(node* x) {
	if (x == nullptr) return;
	cout << x->ele << " ";
	//cout << "x->left" << endl;
	_print(x->left);
	//cout << "x->right" << endl;
	_print(x->right);
}

void BinaryTree::print(){
	_print(root);
	cout << endl;
}


BinaryTree::~BinaryTree() {
	clear();
	root = NULL;
}

void BinaryTree::ResetTree(const int* arr, int len) {
	clear();
	for (int i = 0; i < len; ++i) {
		insert(arr[i]);
	}
}

//===================
void Test1() {
  BinaryTree t1;
  t1.print();
  int len;
  cin >> len;
  int* arr = new int[len+1];
  int index = 0;
  while (index < len) cin >> arr[index++];
  BinaryTree t2(arr, len);
  t2.print();
  int inser;
  int times;
  cout << "times:(insert)" << endl;
  cin >> times;
  while (times--) {
    cin >> inser;
    t2.insert(inser);
  }
  t2.print();
  cout << "times:delete" << endl;
  cin >> times;
  int del;
  while (times--) {
    cin >> del;
    t2.Delete(del);
  }
  t2.print();
  //==
  BinaryTree t3 = t2;
  t3.print();
  t3.clear();
  t3.clear();
  t3.print();
  t2.print();
  // cout << &t3 << endl;
  // cout << &t2 << endl;
  delete []arr;

  
}

void Test2() {
  BinaryTree t1;
  t1.Delete(10);
  t1.clear();
  t1.print();
  int times;
  int tmp;
  cin >> times;
  while (times--) {
    cin >> tmp;
    t1.insert(tmp);
  }
  t1.Delete(tmp);
  t1.print();
}
void Test3() {
  int arr[10] = {9,4,3,1,2,10,15,17,18,6};
  BinaryTree t1(arr, 10);
  t1.print();
  arr[9] = 5;
  t1.ResetTree(arr, 10);
  t1.print();
  t1.clear();
  t1.ResetTree(arr, 10);
  t1.print();
}
int main() {
  //Test1();
  //Test2();
 //Test3();
 BinaryTree t;
 for (int i = 0; i < 3; ++i) t.insert(i);
 for (int i = 0; i< 3; ++i) t.Delete(i);
 cout << new_t << endl << delete_t << endl;
}
