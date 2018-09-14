#include <iostream>
#include <queue>

using namespace std;


void solve(int l, int m)
{
	int ans=0, c, t;
	string s;
	vector<int> left, right;
	bool lft = true;
	l *= 100;
	while(m--){
		cin >> c >> s;
		if(s == "left"){
			if(!left.empty()){
				t = left.back();
				if(t + c <= l)
				{
					left.pop_back();
					left.push_back(t + c);
				}
				else
				{
					left.push_back(c);
				}
			}
			else{
				left.push_back(c);
			}
		}
		if(s == "right"){
			if(!right.empty()){
				t = right.back();
				if(t + c <= l)
				{
					right.pop_back();
					right.push_back(t + c);
				}
				else
				{
					right.push_back(c);
				}
			}
			else{
				right.push_back(c);
			}


		}
	}

	while(!(left.empty() && right.empty()))
	{
		if(lft){
			if(!left.empty()){
				left.pop_back();
			}
		}
		else{
			if(!right.empty()){
				right.pop_back();
			}
		}
		ans++;
		lft = !lft;
	}
	cout << ans << endl;
}
int main()
{
	int l, m;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>l>>m;
		solve(l, m);
	}
	return 0;
}