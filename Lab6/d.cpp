#include <iostream>

#define MAXN int(1e5+10)
#define MN  int(-1e9-10)
using namespace std;
struct Heap
{
	int sz;
	int lpos;
	int val[4*MAXN];

	void init() {
		sz = 0;
		lpos = 1;
		for(int i=0; i<4*MAXN; i++) {
			val[i] = MN;
		}
	}

	int add(int x) {
		int pos = lpos;
		int npos = pos/2;
		sz++;
		lpos++;
		val[sz] = x;
		while(pos > 1 && val[pos] > val[npos]) {
			swap(val[pos], val[npos]);
			pos = npos;
			npos = pos/2;
		}
		return pos;
	}

	int siftDown(int i, int x) {
		int pos = i;
		int npos = pos*2;

		if(val[npos] < val[npos+1]) {npos++;}
		val[pos] -= x;

		while(val[pos] < val[npos]) {
			swap(val[pos], val[npos]);
			pos = npos;
			npos = pos*2;
			if(val[npos] < val[npos+1]) npos++;
		}
		return pos;
	}

	int getMax() {
		
		int res = val[1], sift = 0;
		val[1] = val[sz];
		val[sz] = MN;
		sz--;
		lpos--;
		if(sz != 0) 
		{
			sift =  siftDown(1, 0);
		}
		cout << sift << ' ';
		return res;
	}

	void print() {
		for(int i=1; i<=sz; i++) {
			cout << val[i] << ' ';
		}
		cout << '\n';
	}
};

int main()
{
	Heap mh;
	mh.init();

	int n, m, x, t;
	cin >> n >> m;
	while(m--){
		cin>>t;
		if(t == 1) {
			if(mh.sz == 0)
			{
				cout << -1;
			}
			else 
			{
				cout << mh.getMax();
			}
		}
		if(t == 2) {
			cin >> x;
			if(mh.sz == n)
			{
				cout << -1;
			}
			else 
			{
				cout << mh.add(x);
			}
		}

		cout << '\n';
	}

	mh.print();
	return 0;
}