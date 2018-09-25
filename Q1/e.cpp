#include <bits/stdc++.h>

#define MAXN (int)1e6+100
using namespace std;


void solve()
{
	int n, cnt, x;
	queue<int> q1, q2;
	bool used[MAXN];
	cin >> n;
	for(int i=0; i<=n; i++){
		used[i] = false;
	}

	q1.push(n);
	q2.push(0);
	while(!q1.empty() && q1.front() != 0){
		x = q1.front();
		cnt = q2.front();
		q1.pop();
		q2.pop();

		if(x == 0){
			break;
		}

		for(int i=2; i<=sqrt(x); i++){
			if(x % i == 0)
			{
				if(!used[x/i]){
					q1.push(x/i);
					q2.push(cnt+1);
					used[x/i] = true;
				}
			}
		}
		if(!used[x-1]){
			q1.push(x-1);
			q2.push(cnt+1);
			used[x-1] = true;
		}
	}

	cout << q2.front() << endl;
	
	
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