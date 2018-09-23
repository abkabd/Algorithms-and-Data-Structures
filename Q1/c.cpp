#include <iostream>
#include <deque>
using namespace std;
void solve()
{
	deque<int> d;
	int n, m, x;
	string s;
	cin >> n >> m;
	while(m--){
		cin >> s;
		if(s == "pushLeft"){
			cin >> x;
			if(d.size() == n){
				cout << "The queue is full\n";
			}
			else {
				d.push_front(x);
				cout << "Pushed in left: " << x << "\n";
			}
		}
		if(s == "pushRight"){
			cin >> x;
			if(d.size() == n){
				cout << "The queue is full\n";
			}
			else {
				d.push_back(x);
				cout << "Pushed in right: " << x << "\n";
			}
		}
		if(s == "popLeft"){
			if(d.empty()){
				cout << "The queue is empty\n";
			}
			else {
				x = d.front();
				d.pop_front();
				cout << "Popped from left: " << x << "\n";
			}
		}
		if(s == "popRight"){
			if(d.empty()){
				cout << "The queue is empty\n";
			}
			else {
				x = d.back();
				d.pop_back();
				cout << "Popped from right: " << x << "\n";
			}
		}
	}
}
int main()
{
	int t, cs = 0;
	cin>>t;
	while(t--)
	{
		cs++;
		cout << "Case " << cs << ":\n";
		solve();
	}
}