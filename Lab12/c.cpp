#include <bits/stdc++.h>

#define MAXN (int)1e6+100
#define ll long long
using namespace std;

long long h[MAXN], p[MAXN];
int sz;
string s, t;

map<ll, vector<string> > ans;
vector<string> v;

void init() {
	p[0] = 1;
	for(int i=1; i<MAXN; i++) {
		p[i] = p[i-1] * 31;
	}
}

ll getHash(int l, int r) {
	long long tmp = h[r];
	if(l > 0) tmp -= h[l-1];
	return tmp*p[sz-r-1];
}

ll countHash() {
	ll hs = t[0] - 'a' + 1;
	for(int i=1; i<t.size(); i++) {
		hs = hs + (t[i] - 'a' + 1)*p[i];
	}
	return hs;
}
void solve() {
	ll mx = -1;

	h[0] = s[0] - 'a' + 1;

	for(int i=1; i<sz; i++) {
		h[i] = h[i-1] + (s[i] - 'a' + 1)*p[i];
	}

	for(int x=0; x<v.size(); x++) {
		int k = v[x].size();
		t = v[x];
		ll hs = countHash();
		ll cnt = 0;
		for(int i=0; i < sz-k+1; i++) {
			if(hs*p[sz - k] == getHash(i, i+k-1))
			{
				cnt++;
			}
		}
		mx = max(mx, cnt);
		ans[cnt].push_back(t);
	}

	cout << mx << endl;

	for(int i=0; i<ans[mx].size(); i++)
	{
		cout << ans[mx][i];
		if(i != ans[mx].size() - 1)
			cout << endl;
	}
	v.clear();
	ans.clear();
}


int main() {
	init();
	int n = 1;
	bool ok = false;
	while(true)
	{
		cin>>n;
		if(n == 0)break;

		if(ok && n != 1){
			cout << endl;
		}

		for(int i=0; i<n; i++) {
			cin>>t;
			v.push_back(t);
		}
		cin>>s;
		sz = s.size();
		solve();
		ok = true;
	}
	
}