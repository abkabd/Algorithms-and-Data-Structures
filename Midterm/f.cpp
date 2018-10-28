#include <iostream>

using namespace std;

int main()
{	
	int n, a[1010], mh=0, cnt=1, ch = 1;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i] > a[j]) swap(a[i], a[j]);
		}
	}

	for(int i=1; i<n; i++) {
		if(a[i] == a[i-1]){
			ch++;
		}
		else {
			mh = max(ch, mh);
			ch = 1;
			cnt++;
		}
	}

	cout << max(mh, ch) << ' ' << cnt;
	
	return 0;
}