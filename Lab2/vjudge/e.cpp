#include <iostream>
#include <vector>

using namespace std;

void solve(int n)
{
	int x, cur=1;
	vector<int> v;

	for(int i=0; i<n; i++){
		cin>>x;
		v.push_back(x);
		while(!v.empty() && cur == v.back()){
			cur++;
			v.pop_back();
		}
	}
	if(v.empty()){
		cout << "yes\n";
	}
	else{
		cout << "no\n";
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)break;
		solve(n);
	}
	return 0;
}