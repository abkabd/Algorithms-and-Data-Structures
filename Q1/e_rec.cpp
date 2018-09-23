#include <bits/stdc++.h>

#define MAXN (int)1e6+10
using namespace std;


void solve()
{
	int n;
	int mp[1000];
	queue<int> q;
	cin >> n;
	if(n == 0)
	{
		cout << 0 << endl;
		return;
	}
	q.push(n);
	
	mp[n] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x == 0){
			break;
		}

		for(int i=2; i<=sqrt(x); i++){
			if(x % i == 0)
			{
				
				if(mp[x/i] != 0)
				{
					mp[x/i] = min(mp[x] + 1, mp[x/i]);
					q.push(x/i);
				}
				else
				{
					mp[x/i] = mp[x] + 1;
				}
			}
		}

		if(mp[x-1] != 0)
		{
			mp[x-1] = min(mp[x-1], mp[x] + 1);
		}
		else
		{
			mp[x-1] = mp[x] + 1;
		}

		q.push(x-1);
	}

	cout << mp[1] + 1 << endl;
	
	
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