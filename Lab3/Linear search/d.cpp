#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], x;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}

	cin>>x;
	for(int i=1; i<=n; i++){
		if(x == a[i]){
			cout << i << ' ';
		}
	}

	return 0;
}