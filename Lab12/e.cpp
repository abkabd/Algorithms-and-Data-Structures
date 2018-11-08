#include <bits/stdc++.h>

using namespace std;

string s;

void solve()
{
	int n = s.size(), x;
	vector<int> p(n);
	for(int i=1; i<n; i++)
	{
		int j = p[i-1];

		while(j > 0 && s[i] != s[j])
			j = p[j-1];
		if(s[i] == s[j]) j++;
		p[i] = j;
	}

	x = s.substr(0, n - p[n-1]).size();
	if(n % x == 0)
	{
		cout << n/x;
	}
	else cout << 1;
	cout << endl;
}
int main()
{
	while(cin>>s && s != ".")
	{
		solve();
	}
}