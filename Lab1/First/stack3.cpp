#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int t = 0;

void push(int n) {
	a.push_back(n);
	cout << "ok\n";
}

void pop() {
	if(a.empty())
	{
		cout << "error\n";
		return;
	}

	cout << a.back() << "\n";
	a.pop_back();
}

void back() {
	if(a.empty())
	{
		cout << "error\n";
		return;
	}

	cout << a.back() << "\n";
}

void size() {
	cout << a.size() << "\n";
}

void clear() {
	a.clear();
	cout << "ok\n";
}

void exit() {
	cout << "bye\n";
}

int main()
{
	string q;
	int x;

	do
	{
		cin >> q;
		if(q == "push"){
			cin >> x;
			push(x);
		}
		if(q == "pop"){
			pop();
		}
		if(q == "back"){
			back();
		}
		if(q == "size"){
			size();
		}
		if(q == "clear"){
			clear();
		}
		if(q == "exit"){
			exit();
		}
	}
	while(q != "exit");
	return 0;
}