#include <bits/stdc++.h>

using namespace std;

vector<int> ct;
vector<vector<int> > g;
vector<char> was;

map<int, set<int> > mp;

void go(int v, int p)
{
	was[v] = true;
	mp[v].insert(p);
	for(int j=0; j<g[v].size(); j++)
	{
		int x = g[v][j];
		if(!was[x])
		{
			go(x, p);
		}
	}
}
void solve(int cs)
{
	ct.clear();
	g.clear();
	
	int ans = 0, mx = 0;
	int n, m, k;
	int u, v;
	int ctz[1100];
	cin>>k>>n>>m;

	ct.resize(n+1);
	g.resize(n+1);

	for(int i=0; i<k; i++)
	{
		cin>>ctz[i];
	}

	for(int i=0; i<m; i++)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}

	for(int i=0; i<k; i++)
	{
		was.clear();
		was.resize(n+1);
		go(ctz[i], i);
	}

	for(int i=1; i<=n; i++)
	{
		if(mp[i].size() == k) ans++;
	}

	cout << "Case " << cs << ": " << ans << endl;
}

int main()
{
	int t, cs=1;
	cin>>t;
	while(cs <= t)
	{
		solve(cs);
		cs++;
	}
}