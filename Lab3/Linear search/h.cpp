#include <iostream>

using namespace std;

int main()
{
	int n, a[110][110],x;
	cin>>x;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
		cin>>a[i][j];
		}
	}

	for(int i=0; i<n; i++){
		bool ok = false;
		for(int j=0; j<n; j++){
			if(x == a[j][i]){
				ok = true;
				break;
			}
		}
		cout<<(ok ? "YES" : "NO")<<endl;
	}
	return 0;
}