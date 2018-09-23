#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	int step[10000];
	queue<int> q;
	cin >> n;

	q.push(n);
	for(int i = 0; i<=n; i++){
		step[i] = 1000100;
	}
	step[n] = 0;
	while(!q.empty() || q.front() != 0){
		int x = q.front();
		q.pop();
		for(int i=2; i<=sqrt(x); i++){
			if(x % i == 0)
			{
				q.push(x/i);
				step[x/i] = min(step[x] + 1, step[x/i]);
			}
		}
		step[x-1] = min(step[x-1], step[x] + 1);
	}

	cout << step[1] + 1 << endl;
}
int main()
{
	int t, cs = 0;
	cin>>t;
	while(t--)
	{
		solve();
	}
}