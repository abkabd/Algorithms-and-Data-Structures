#include <iostream>

using namespace std;

int main()
{	
	int a[5], ix = 0;
	a[1] = a[2] = a[3] = 0;
	
	string s;
	cin>>s;

	for(int i=0; i<s.size(); i++) {
		if(s[i] != '+'){
			a[s[i]-'0']++;
			ix = max(ix, s[i]-'0');
		}
	}

	for(int i=1; i<=3; i++) {
		for(int j=0; j<a[i]; j++) {
			cout << i;
			if(!(i==ix && j==a[i]-1)) cout << '+';
		}
	}
	
	return 0;
}