#include <iostream>

using namespace std;

int a[200], t = 0;

void push(int n) {
	a[t] = n;
	t++;
	cout << "ok\n";
}

void pop() {
	t--;
}

void back() {
	cout << a[t-1] << "\n";
}

void size() {
	cout << t << "\n";
}

void clear() {
	t = 0;
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
			back();
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