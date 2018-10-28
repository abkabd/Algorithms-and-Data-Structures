#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority[300];
stack<int> num;
stack<char> op;

bool isNum(char ch) {
	return (ch >= '0' && ch <= '9'); 
}

bool isOp(char ch) {
	return (ch == '+' || ch == '-' || ch == '*');
}

void doOp() {
	char curOp = op.top();
	op.pop();
	int y = num.top();
	num.pop();
	int x = num.top();
	num.pop();

	//cout << x << curOp << y << endl;

	if(curOp == '+') num.push(x+y);
	if(curOp == '-') num.push(x-y);
	if(curOp == '*') num.push(x*y);
}

void solve(string s) {
	priority['('] = 0;
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;


	for(int i=0; i<s.size(); i++) {
		if(isNum(s[i]))
		{
			num.push(s[i] - '0');
		}
		if(s[i] == '(')
		{
			op.push(s[i]);
		}
		if(isOp(s[i]))
		{
			while(!op.empty() && priority[s[i]] <= priority[op.top()])
			{
				doOp();
			}
			op.push(s[i]);
		}
		if(s[i] == ')')
		{
			while(op.top() != '(')
			{
				doOp();
			}
			op.pop();
		}
	}

	while(!op.empty()){
		doOp();
	}

	cout << num.top();
}

int main()
{
	string s;
	cin>>s;
	solve(s);
	return 0;
}