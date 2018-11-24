#include <bits/stdc++.h>
	
using namespace std;

map<string, int> mp;
int main() {
	string s;
	int n;
	cin>>n;
	while(n--) {
		cin>>s;
		if(mp[s] == 0) {
			cout << "OK";
		}
		else {
			cout << s << mp[s];
		}
		mp[s]++;
		cout << endl;
	}
}