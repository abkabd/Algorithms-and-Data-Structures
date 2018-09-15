#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], mx = -1010;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	for(int i=1; i<=n; i++){
		mx = max(mx, a[i]);
	}

	cout<<mx;
	return 0;
}