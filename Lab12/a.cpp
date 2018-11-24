#include <bits/stdc++.h>

#define MAXN (int)1e5+100
using namespace std;

long long h[MAXN], p[MAXN];
int n, k;

void init() {
	p[0] = 1;
	for(int i=1; i<MAXN; i++) {
		p[i] = p[i-1] * 31;
	}
}

long long getHash(int l, int r) {
	long long tmp = h[r];
	if(l > 0) tmp -= h[l-1];
	return tmp * p[n-r-1];
}

void solve() {
	set<long long> ans;
	string s, t;
	cin>>n>>k>>s;
	h[0] = s[0] - 'a' + 1;
	
	for(int i=1; i<n; i++) {
		h[i] = h[i-1] + (s[i] - 'a' + 1)*p[i];
	}

	for(int i=0; i<n-k+1; i++)
	{
		ans.insert(getHash(i, i+k-1));
	}

	cout << ans.size() << endl;
}
int main() {
	init();
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	
}