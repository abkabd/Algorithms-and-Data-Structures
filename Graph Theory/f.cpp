#include <bits/stdc++.h>

using namespace std;
vector<vector<int> >g;
vector<char> was;
int st[110], fin[110];
int t = 0;
void dfs(int v)
{
	if(was[v])return;
	t++;
	was[v] = true;
	st[v] = t;
	for(int i=0; i<g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
	}
	t++;
	fin[v] = t;
}

int main(){
	int n, k, u, v;
	cin>>n;
	g.resize(n+1);
	was.resize(n+1);
	for(int i=0; i<n; i++){
		cin>>u>>k;
		for(int j=0; j<k; j++){
			cin>>v;
			g[u].push_back(v);
		}
	}
	for(int i=1; i<=n; i++)
	{
		dfs(i);
	}

	for(int i=1; i<=n; i++)
	{
		cout << i << ' ' << st[i] << ' ' << fin[i] << '\n';
	}
	return 0;
}