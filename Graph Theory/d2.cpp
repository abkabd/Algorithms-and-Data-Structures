#include <bits/stdc++.h>

#define pb push_back
using namespace std;

int n, m, k, u, v;
vector<int> pers;
vector<int> cnt;
vector<char> was;
vector<vector<int> > g;

void dfs(int v){
	if(was[v]) return;
	cnt[v]++;
	was[v] = true;
	for(int i=0; i<g[v].size(); i++)
	{
		dfs(g[v][i]);
	}
}

void solve(int cs) {
	pers.clear();
	g.clear();
	cnt.clear();
	pers.resize(k);
	g.resize(n+1);
	cnt.resize(n+1);

	for(int i=0; i<k; i++) {
		cin>>pers[i];
	}

	for(int i=0; i<m; i++) {
		cin>>u>>v;
		g[u].pb(v);
	}
	for(int i=0; i<pers.size(); i++) {
		was.clear();
		was.resize(n+1);
		dfs(pers[i]);
	}

	int ans = 0;
	for(int i=0; i<cnt.size(); i++) {
		if(cnt[i] == k)ans++;
	}
	cout << "Case " << cs << ": " << ans << "\n";
}

int main()
{
	int t;
	cin>>t;
	for(int i=1; i<=t; i++)
	{
		cin>>k>>n>>m;
		solve(i);
	}
	return 0;
}