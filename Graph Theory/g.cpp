#include <bits/stdc++.h>

#define mp make_pair
using namespace std;
vector<vector<int> >g;
queue<pair<int, int> > q;
vector<char> was;
vector<int> path;
void bfs(int v)
{
	int d;
	q.push(mp(v, 0));
	while(!q.empty())
	{
		v = q.front().first;
		d = q.front().second;
		path[v] = min(d, path[v]);
		was[v] = true;
		q.pop();
		for(int i=0; i<g[v].size(); i++)
		{
			int to = g[v][i];
			if(!was[to])
			{
				q.push(mp(to, d+1));
			}
		}
	}
}

int main(){
	int n, k, u, v;
	cin>>n;
	g.resize(n+1);
	was.resize(n+1);
	path.resize(n+1, 1000);

	for(int i=0; i<n; i++){
		cin>>u>>k;
		for(int j=0; j<k; j++){
			cin>>v;
			g[u].push_back(v);
		}
	}
	
	bfs(1);

	for(int i=1; i<=n; i++)
	{
		if(path[i] == 1000) path[i] = -1;
		cout << i << ' ' << path[i] << '\n';
	}
	return 0;
}