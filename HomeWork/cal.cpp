#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <stack>
#include <cctype>
const bool debug = false;
using namespace std;
template <typename T>
void printStack(T t) {
    if (!debug) {return; }
	while (!t.empty()) {
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
}

int prefix[512];
bool isP(int i) { return i == '(' || i == ')'; } //parenthes

        
bool isCalOp(int i) { // + - * /
	return i == '+' || i == '-' || i == '*' || i == '/';
}
bool isOp(int i) { //all
	return isP(i) || isCalOp(i);
}
bool lessPrefix(int lhs, int rhs) {
	return prefix[lhs] <= prefix[rhs];
}
bool greaterPrefix(int lhs, int rhs) {
	return ! lessPrefix(lhs, rhs);
}
double cal(double num1, double num2, char op) {
	if (op == '+') {
		return num1 + num2;
	} else if (op == '-') {
		return num1 - num2;
	}else if (op == '*') {
		return num1 * num2;
	} else if (op == '/') {
		return num1 / num2;
	} else {
		cout << "error!cal()!   " << op << endl;
		return 0;
	}
}
void calculateAll(stack<double>& sint, stack<char>& sop, int p)  {
//        cout << "vefore all,insize: ";printStack(sint);printStack(sop); //TODO
	while (!sop.empty() && prefix[sop.top()] >= p) {
		int op = sop.top();
		sop.pop();
		double num2 = sint.top();
		sint.pop();
                //if (sint.empty() || (sop.empty() || sop.top() == '(')) {
                //    if (op == '-') {
                //        num2 = -num2;
                //    }
                //    sint.push(num2);
                //}
		double num1 = sint.top();
		sint.pop();
		double ans = cal(num1, num2, op);
		sint.push(ans);
//		cout << "all,insize: ";printStack(sint);printStack(sop); //TODO
	}
}
void calculateUntilP(stack<double>& sint,stack<char>& sop) {
	while (sop.top() != '(') {
//		cout << "before p insize: ";printStack(sint); printStack(sop);//TODO
		char op = sop.top();
		sop.pop();
		double num2 = sint.top();
		sint.pop();
		double num1 = sint.top();
		sint.pop();
		double ans = cal(num1, num2, op);
		sint.push(ans);
//		cout << "p insize: ";printStack(sint); printStack(sop);//TODO
	}
        sop.pop();
 //       cout << "end p insize: ";printStack(sint); printStack(sop);//TODO
}
		
int main() {
	prefix['+'] = prefix['-'] = 1;
	prefix['*'] = prefix['/'] = 2;
	prefix['('] = prefix[')'] = 0;
	int m;
	cin >> m;
	cin.get();
	while (m--) {
            bool behindP = true;
            string s;
            getline(cin, s);
            s.erase(remove(s.begin(), s.end(), ' '), s.end());
            stringstream sin(s);

            stack<double> sint;
            stack<char> sop;
            while (sin.peek() != EOF) {
                    if (sin.peek() == ' ') {
                            sin.get();
                            continue;
                    }
                    if (!behindP && isCalOp(sin.peek())) {
                            behindP = false;
                            char op;
                            sin >> op;
                            if (!sop.empty() && lessPrefix(op, sop.top())) {
  //                                  cout << "calculateAll " << op << endl; // TODO
                                    printStack(sint);printStack(sop);
                                    calculateAll(sint, sop, prefix[op]);
                                    sop.push(op);
                            } else {
                                    sop.push(op);
                            }
                    } else if (isdigit(sin.peek()) || sin.peek() == '.' || sin.peek() == '-' || sin.peek() == '+') {
                            double num;
                            sin >> num;
                            sint.push(num);
                            behindP = false;
                    } else if (sin.peek() == '(') {
                            behindP = true;
                            char op; sin >> op;
                            sop.push(op);
                    } else {
                            behindP = false;
                             //op == ')'
                            char op; sin >> op;
//				cout << "debug: op == )" << op << endl; //TODO
                            calculateUntilP(sint, sop);
                    }

            }
//		cout << "end" << endl; //TODO
            calculateAll(sint, sop, -5);
            printf("%.3f\n", sint.top());
    }
}
