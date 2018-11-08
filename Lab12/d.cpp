#include <bits/stdc++.h>

#define MAXN (int)2e6+100

using namespace std;


void solve()
{
	vector<int> v;
	string s, t;
	cin>>s>>t;
	s = t + '#' + s;

	vector<int> p(s.size());

	for(int i=1; i<s.size(); i++)
	{
		int j = p[i-1];

		while(j > 0 && s[i] != s[j])
			j = p[j-1];
		if(s[i] == s[j]) j++;

		p[i] = j;

		if(p[i] == t.size())
		{
			v.push_back(i - 2*t.size()+1);
		}
	}
	if(v.size() == 0) {
		cout << "Not Found\n";
		return;
	}
	cout << v.size() << '\n';
	for(int i=0; i<v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
}