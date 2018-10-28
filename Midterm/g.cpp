#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100100], cnt=0;

void quicksort(int l, int r) {
    int init_l = l;
    int init_r = r;
    int mid = a[(l + r) / 2];
    while (l < r) {
        while (a[l] < mid) l++;
        while (a[r] > mid) r--;
        if (l <= r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    if (init_l < r)
        quicksort(init_l, r);
    if (l < init_r)
        quicksort(l, init_r);
}

int main()
{
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	quicksort(0, n-1);
	int mn = a[0], mx = a[n-1];
	for(int i=0; i<n; i++) {
		if(a[i] > mn && a[i] < mx) cnt++;
	}

	cout << cnt;
	
	return 0;
}