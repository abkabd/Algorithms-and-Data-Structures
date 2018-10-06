#include <iostream>

#define MAXN int(1e5+10)
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
			val[i] = int(-1e9-10);
		}
	}

	void add(int x) {
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
	}

	int siftDown(int i, int x) {
		int pos = i;
		int npos = pos*2;

		if(val[npos] < val[npos+1]) {npos++;}
		val[pos] -= x;

		while(val[pos] < val[npos]) {
			//cout << pos << "->" << npos <<'\n';
			swap(val[pos], val[npos]);
			pos = npos;
			npos = pos*2;
			if(val[npos] < val[npos+1]) npos++;
		}
		//cout << "-*-*-*-*-*-*-*-*-*-\n";
		return pos;
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
	int n, m, x, i;
	cin >> n;
	while(n--){
		cin>>x;
		mh.add(x);
	}

	cin >> m;
	while(m--){
		cin >> i >> x;
		cout << mh.siftDown(i, x) << '\n';
	}

	mh.print();
	return 0;
}