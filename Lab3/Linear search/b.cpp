#include <iostream>

using namespace std;

int main()
{
	int n, a[1010], x;
	bool ok = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	cin>>x;
	for(int i=0; i<n; i++){
		if(x == a[i]){
			ok = true;
			break;
		}
	}
	cout<<(ok ? "YES" : "NO");

	return 0;
}