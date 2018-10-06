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

	int siftUp(int i, int x) {
		int pos = i;
		int npos = pos/2;
		val[pos] += x;
		while(npos>0 && val[pos] > val[npos]) {
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

	int deleteMax() {
		int res = val[1];
		val[1] = val[sz];
		val[sz] = MN;
		sz--;
		siftDown(1, 0);
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
	/*
	Heap mh;
	mh.init();
	mh.add(x);
	mh.siftUp(i, x);
	mh.siftDown(i, x);
	mh.getMax();
	mh.print();
	return 0;
}