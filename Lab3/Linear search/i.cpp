#include <iostream>

using namespace std;

int main()
{
	int n, m, cnt = 0;
	cin>>n>>m;

	int a[n][m], mnrow[n], mxcol[m];
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>a[i][j];
		}
	}

	for(int i=0; i<n; i++){
		int mn = 2000;
		for(int j=0; j<m; j++){
			mn = min(mn, a[i][j]);
		}
		mnrow[i] = mn;
	}

	for(int i=0; i<m; i++){
		int mx = -2000;
		for(int j=0; j<n; j++){
			mx = max(mx, a[j][i]);
		}
		mxcol[i] = mx;
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mnrow[i] == a[i][j] && mxcol[j] == a[i][j]) cnt++;
		}
	}

	cout << cnt;
	return 0;
}