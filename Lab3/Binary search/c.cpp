#include <iostream>
#include <cmath>

using namespace std;
int a[100100];

int binsearch(int l, int r, int x)
{
	int mid = (l+r)/2;
	if(l>r) return r;
	if(x < a[mid]) return binsearch(l, mid-1, x);
	else if(x > a[mid]) return binsearch(mid+1, r, x);
	else return mid;
}

int main()
{
	int n, k, x, i;
	cin>>n>>k;
	for(i=0; i<n; i++){
		cin>>a[i];
	}

	while(k--){
		cin>>x;
		i = binsearch(0, n-1, x);
		cout << ((i>=0) && a[i] == x ? "YES" : "NO") << '\n';
	}
	
	return 0;
}