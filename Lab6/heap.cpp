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

	int updateElement(int pos, int val) {
		int newPos = 0;
		val[pos] += x;
		if(x <= 0)
		{
			newPos = siftDown(pos);
		}
		if(x > 0)
		{
			newPos = siftUp(pos);
		}

		return newPos;
	}

	int getTop() {
		return val[1];
	}

	int deleteTop() {
		int res = val[1];
		val[1] = val[sz];
		val[sz] = MN;
		sz--;
		siftDown(1);
		return res;
	}

	int deleteElement(int pos) {
		if(x > sz || x <= 0)
		{
			return -1;
		}

		int res = val[pos];
		val[pos] = val[sz];
		val[sz] = MN;
		sz--;
		if(sz == 0)
		{
			sift = 0;
		}
		else if(val[pos] < max(val[pos*2], val[pos*2+1]))
		{
			sift = siftDown(pos);
		}
		else if(val[pos] != val[pos/2])
		{
			sift = siftUp(pos);
		}
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
	mh.siftUp(i);
	mh.siftDown(i);
	mh.updateElement(pos, x);
	mh.getMax();
	mh.print();
	return 0;
	*/
}