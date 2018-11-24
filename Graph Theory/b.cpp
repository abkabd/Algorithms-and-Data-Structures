#include <bits/stdc++.h>

using namespace std;

char a[110][110];
int ans;
void mark(int x, int y)
{
	if(a[x][y] == '*') return;
	if(a[x][y] == '@')
	{
		a[x][y] = '*';
		mark(x, y-1);
		mark(x, y+1);
		mark(x-1, y-1);
		mark(x-1, y);
		mark(x-1, y+1);
		mark(x+1, y-1);
		mark(x+1, y);
		mark(x+1, y+1);
	}
}

void solve(int n, int m)
{
	ans = 0;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>a[i][j];
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i][j] == '@')
			{
				mark(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	int n=1, m=1;
	while(true)
	{
		cin>>n>>m;
		if(n == 0) break;
		solve(n, m);
	}
}