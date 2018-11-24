#include <bits/stdc++.h>

using namespace std;

map<int, vector<string> > ans;
vector<string> v;

string s;

void solve() {
	int mx = 0;

	for(int x=0; x<v.size(); x++)
	{
		int cnt=0, sz = v[x].size();
		string t = (v[x] + '#' + s);
		vector<int> p(t.size());

		for(int i=1; i<t.size(); i++)
		{
			int j = p[i-1];

			while(j > 0 && t[i] != t[j])
				j = p[j-1];
			if(t[i] == t[j]) j++;

			p[i] = j;

			if(p[i] == sz) cnt++;

		}

		mx = max(mx, cnt);
		ans[cnt].push_back(v[x]);
	}	

	cout << mx << endl;

	for(int i=0; i<ans[mx].size(); i++)
	{
		cout << ans[mx][i] << endl;
	}

	v.clear();
	ans.clear();
}


int main() {
	int n;
	string t;
	
	while(true)
	{
		cin>>n;
		getline(cin, t);
		if(n == 0)break;

		for(int i=0; i<n; i++) {
			getline(cin, t);
			v.push_back(t);
		}
		getline(cin, s);
		solve();
	}
	
}