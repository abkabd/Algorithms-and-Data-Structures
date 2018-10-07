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

	int siftDown(int i) {
		int pos = i;
		int npos = pos*2;

		if(val[npos] < val[npos+1]) {npos++;}

		while(val[pos] < val[npos]) {
			swap(val[pos], val[npos]);
			pos = npos;
			npos = pos*2;
			if(val[npos] < val[npos+1]) npos++;
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
	for(int i=1; i<=n; i++){
		cin >> mh.val[i];
	}
	mh.sz = n;
	for(int i=n; i>0; i--) {
			mh.siftDown(i);
	}

	mh.print();
	return 0;
}