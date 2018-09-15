#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], mn=1000, mx=-1000;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}

	for(int i=1; i<=n; i++){
		if(a[i] == mx)cout<<mn<<' ';
		else cout<<a[i]<<' ';
	}
	return 0;
}