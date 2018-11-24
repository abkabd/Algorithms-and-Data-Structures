#include <bits/stdc++.h>

using namespace std;


vector<char> was;
vector<vector<int> > g;

void mark(int v)
{
	for(int i=0; i<g[v].size(); i++)
	{
			int pr = g[v][i];
			if(!was[pr]) {
				mark(pr);
			}
	}
	if(!was[v]) {
		cout << v << ' ';
		was[v] = true;
	}
}

void solve(int n, int m)
{
	was.clear();
	g.clear();
	was.resize(n+1);
	g.resize(n+1);

	int u, v;
	for(int i=0; i<m; i++)
	{
		cin>>u>>v;
		g[v].push_back(u);
	}

	for(int i=1; i<=n; i++)
	{
		mark(i);
	}
	cout << endl;
}

int main()
{
	int n=1, m=1;
	while(n || m)
	{
		cin>>n>>m;
		solve(n, m);
	}
}