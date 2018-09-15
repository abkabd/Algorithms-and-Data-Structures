#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], mn1, mn2;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	mn1 = a[1];
	mn2 = a[2];

	if(a[1] > a[2]){
		swap(mn1, mn2);
	}

	for(int i=3; i<=n; i++){
		if(a[i] <= mn1){
			mn2 = mn1;
			mn1 = a[i];
		}
		else if(a[i] < mn2){
			mn2 = a[i];
		}
	}

	cout<<mn1<<' '<<mn2;
	return 0;
}