#include <iostream>
#include <cmath>
using namespace std;

long long int a[100100], p[100100];

int binsearch(int l, int r, int x, int fix)
{
	while(l < r){
	int mid = (l + r) / 2;
	int cursum = p[mid] - p[fix - 1];
		if(x <= cursum){
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return r;
}

int main()
{	
	int n, k, ans = 1e9+10;
	cin>>n>>k;

	p[0] = 0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		p[i] = p[i-1] + a[i];
	}

	for(int i=1; i<=n; i++) {
		int idx = binsearch(i, n, k, i);
		//cout << "------------ "<<idx<<" --------------\n";
		//cout <<idx << ' ' << p[idx] - p[i-1] << '\n';
		//cout << p[idx] - p[i-1] << endl;
		if(p[idx] - p[i-1] >= k)
		{
			ans = min(ans, abs(idx - i) + 1);
		}
		
	}
	cout << ans;
	return 0;
}