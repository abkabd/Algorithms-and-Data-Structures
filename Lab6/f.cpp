#include <iostream>

#define MAXN int(1e5+10)
#define MN  int(-1e9-10)
using namespace std;
struct Heap
{
	int sz;
	int val[4*MAXN];

	void init() {
		sz = 0;
		for(int i=0; i<4*MAXN; i++) {
			val[i] = MN;
		}
	}

	int add(int x) {
		sz++;
		val[sz] = x;
		return siftUp(sz);
	}

	int siftUp(int i) {
		int pos = i;
		int npos = pos/2;

		while(npos>0 && val[pos] > val[npos]) {
			swap(val[pos], val[npos]);
			pos = npos;
			npos = pos/2;
		}
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

	int n, x;
	cin >> n;
	while(n--) {
		cin>>x;
		mh.add(x);
	}

	mh.print();
	return 0;
}