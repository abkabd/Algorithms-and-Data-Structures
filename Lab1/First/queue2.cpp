#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int h = 0;

void size() {
	cout << v.size() - h << "\n";
}

bool empty() {
	return (v.size() - h) == 0;
}

void push(int x) {
	v.push_back(x);
	cout << "ok\n";
}

void pop() {
	if(empty()) {
		cout << "error\n";
		return;
	}
	cout << v[h++] <<"\n";
}

void front() {
	if(empty()) {
		cout << "error\n";
		return;
	}
	cout << v[h] << "\n";
}

void clear() {
	v.clear();
	h = 0;
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
		if(q == "front"){
			front();
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