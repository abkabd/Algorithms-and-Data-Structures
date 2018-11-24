#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, u, v, k;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>u>>k;
		vector<int> a(n+1);
		for(int j=0; j<k; j++)
		{
			cin>>v;
			a[v] = 1;
		}

		for(int j=1; j<=n; j++)
		{
			cout << a[j];
			if(j != n) cout << ' ';
		}
		cout << endl;
	}
}