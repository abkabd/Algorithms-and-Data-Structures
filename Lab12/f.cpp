#include <bits/stdc++.h>

using namespace std;

int pref_func(string s)
{
	int mx = 0;
	vector<int> p(s.size());
	for(int i=1; i<s.size(); i++)
	{
		int j = p[i-1];

		while(j > 0 && s[i] != s[j])
			j = p[j-1];
		if(s[i] == s[j]) j++;

		p[i] = j;

		mx = max(mx, p[i]);
	}

	return mx;
}

void solve() {
	string s, t, t1;
	cin>>s;
	int n = s.size(), ans = 0;
	for(int c=0; c<n; c++)
	{
		t1 += s[c];
		int mx = 0;
		t = s + t1;
		reverse(t1.begin(), t1.end());
		ans += t1.size() + 1 - pref_func(t1);
		reverse(t1.begin(), t1.end());

	}
	cout << ans - s.size() << endl;

}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	
}