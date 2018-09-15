#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, a[1010], x, idx = 0, df=2000;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	cin>>x;
	for(int i=0; i<n; i++){
		if(abs(x - a[i]) < df){
			idx = i;
			df = abs(x - a[i]);
		}
	}
	cout<<a[idx];

	return 0;
}