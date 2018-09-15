#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], x, cnt = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	cin>>x;
	for(int i=0; i<n; i++){
		cnt += (x==a[i]);
	}
	cout<<cnt;

	return 0;
}