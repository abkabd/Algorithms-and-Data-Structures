#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], mx1=-10000, mx2=-10000;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	for(int i=1; i<=n; i++){
		if(a[i] >= mx1){
			if(mx1 != a[i]) {
				mx2 = mx1;
				mx1 = a[i];
		}
		else if(a[i] > mx2){
			mx2 = a[i];
		}
	}

	cout<<mx2;
	return 0;
}