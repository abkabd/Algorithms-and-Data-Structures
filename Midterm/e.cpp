#include <iostream>

using namespace std;

long long int a[100100], p[100100];

int binsearch(int l, int r, int x)
{

	int mid = (l+r)/2;
	if(l>=r) return r;
	if(x <= p[mid]) return binsearch(l, mid, x);
	else if(x > p[mid]) return binsearch(mid+1, r, x);
	else return mid;
}

int main()
{	
	int n, m, x;
	cin>>n;
	p[0] = 0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		p[i] = p[i-1] + a[i];
	}

	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>x;
		cout << binsearch(1, n, x) << endl;
	}
	return 0;
}