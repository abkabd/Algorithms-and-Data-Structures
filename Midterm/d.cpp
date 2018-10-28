#include <iostream>
#include <cmath>
using namespace std;

long long int a[100100], p[100100];

int binsearch(int l, int r, int x, int fix)
{
	int mid = (l+r)/2;
	int cursum = p[mid] - p[fix-1];
	//cout << mid << '\n';
	if(l >= r) return r;
	if(x <= cursum) return binsearch(l, mid, x, fix);
	else if(x > cursum) return binsearch(mid+1, r, x, fix);
	else return mid;
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