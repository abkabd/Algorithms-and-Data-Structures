#include <bits/stdc++.h>

#define pb push_back
using namespace std;
int n, m, u, v;
vector<vector<int> >g;
vector<int> color;
bool dfs(int v, int col) {
	if(color[v]) return true;
	color[v] = col;
	bool res = true;
	for(int i=0; i<g[v].size(); i++) {
		int to = g[v][i];
		if(color[v] == color[to]) {
			//cout << v<<'-'<<color[v] <<" "<<to<<'-'<<color[to]<<endl;
			return false;
		}
		res = res & dfs(to, max(1, (col+1)%3));
	}
	return res;
}
void solve()
{
	color.clear();
	g.clear();
	color.resize(n);
	g.resize(n);
	while(m--)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=0; i<n; i++)
	{
		if(color[i]==0 && dfs(i, 1)==false)
		{
			cout << "NOT BICOLORABLE.\n";
			return;
		}
	}
	cout << "BICOLORABLE.\n";
}
int main()
{
	while(true)
	{
		cin>>n;
		if(n == 0) break;
		cin>>m;
		solve();
	}
}