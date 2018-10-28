#include <iostream>
#include <set>
#define MAXN int(1e5+10)
#define MX int(1e9+10)
using namespace std;

multiset<int> st;
multiset<int>::iterator it;
int main()
{
	int n, k, x;
	int a[150150];
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<k; i++) {
		st.insert(a[i]);
	}
	for(int i=k; i<=n; i++) {
		it = st.begin();
		++it;
		for(it = st.begin(); it != st.end(); ++it) {
			cout << *it << ' ';
			break;
		}
		cout << endl;
		//cout << *(it) << '\n';
		st.insert(a[i]);
		//cout << a[i-k] << ' ';//*it << '\n';
		it = st.find(a[i-k]);
		st.erase(it);
		
	}
	return 0;
}