#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], idx = 1;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	for(int i=1; i<=n; i++){
		if(a[idx]<a[i]){
			idx = i;
		}
	}

	cout<<idx;
	return 0;
}