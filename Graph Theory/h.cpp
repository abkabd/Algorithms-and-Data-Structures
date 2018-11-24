#include <iostream>
#include <vector>
#include <algorithm>

#define mp make_pair
using namespace std;
vector<vector<int> >g;
vector<char> was;
vector<pair<int, pair<int, int> > >edges;

bool cmp(pair<int, pair<int, int> >a, pair<int, pair<int, int> >b)
{
	if(a.first < b.first) return true;
	return false;
}

bool dfs(int u, int v)
{
	if(u == v) return true;
	if(was[u]) return false;
	was[u] = true;
	bool res = false;
	for(int i=0; i<g[u].size(); i++)
	{
		int to = g[u][i];
		res = (res || dfs(to, v));
	}
	return res;
}


int main(){
	int n, x, ans = 0;
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>x;
			if(i < j)
			{
				edges.push_back(mp(x, mp(i, j)));
			}
		}
	}
	
	sort(edges.begin(), edges.end(), cmp);
	g.resize(n+1);
	was.resize(n+1);

	for(int i=0; i<edges.size(); i++)
	{
		int len = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		//cout << u << " - " << v << ": " << len << endl;
		was.clear();
		was.resize(n+1);
		if(!dfs(u, v))
		{
			g[u].push_back(v);
			g[v].push_back(u);
			ans += len;
		}
	}

	cout << ans;
	return 0;
}