#include <iostream>
#include <vector>

using namespace std;

vector<int> front, back, local;

int h = 0;

int size(){
	return front.size() + back.size();
}


bool empty(){
	return size() == 0;
}

void pf(int x){
	front.push_back(x);
	cout << "ok\n";
}

void pb(int x){
	back.push_back(x);
	cout << "ok\n";
}

void fillfront(){
	int c = back.size()/2;
	while(c >= back.size())
	{
		local.push_back(back.back());
		back.pop_back();
		c--;
	}
	while(!back.empty())
	{
		front.push_back(back.back());
		back.pop_back();
	}
	while(!local.empty())
	{
		back.push_back(local.back());
		local.pop_back();
	}
}

void fillback(){
	int c = front.size()/2;
	while(c >= front.size())
	{
		local.push_back(front.back());
		front.pop_back();
		c--;
	}
	while(!front.empty())
	{
		back.push_back(front.back());
		front.pop_back();
	}
	while(!local.empty())
	{
		front.push_back(local.back());
		local.pop_back();
	}
}

void popf(){
	if(empty()){
		cout << "error\n";
		return;
	}
	if(front.empty()){
		fillfront();
	}
	cout << front.back() << "\n";
	front.pop_back();
}

void popb(){
	if(empty()){
		cout << "error\n";
		return;
	}
	if(back.empty()){
		fillback();
	}
	cout << back.back() << "\n";
	back.pop_back();
}

void frt(){
	if(empty()){
		cout << "error\n";
		return;
	}
	if(front.empty()){
		fillfront();
	}
	cout << front.back() << "\n";
}

void bck(){
	if(empty()){
		cout << "error\n";
		return;
	}
	if(back.empty()){
		fillback();
	}
	cout << back.back() << "\n";
}

void clear(){
	front.clear();
	back.clear();
	cout << "ok\n";
}

void exit(){
	cout << "bye\n";
}

int main()
{
	string q;
	int x;

	do
	{
		cin >> q;
		if(q == "push_front"){
			cin >> x;
			pf(x);
		}
		if(q == "push_back"){
			cin >> x;
			pb(x);
		}
		if(q == "pop_front"){
			popf();
		}
		if(q == "pop_back"){
			popb();
		}
		if(q == "front"){
			frt();
		}
		if(q == "back"){
			bck();
		}
		if(q == "size"){
			cout << size() << "\n";
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