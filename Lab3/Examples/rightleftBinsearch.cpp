#include <iostream>

using namespace std;
int a[100100];


int leftBinsearch(int l, int r, int x){
	cout << l <<' '<< r << endl;

	int mid = (l + r) / 2;
	if(l>r) return l;
	if(a[mid] < x) return leftBinsearch(mid+1, r, x);
	else return leftBinsearch(l, mid-1, x);
}


int rightBinsearch(int l, int r, int x){
	//cout << l <<' '<< r << endl;
	
	int mid = (l + r) / 2;
	if(l>r) return r;
	if(a[mid] <= x) return rightBinsearch(mid+1, r, x);
	else return rightBinsearch(l, mid-1, x);
}

int main(){
	
	int n, m, x, idx;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	while(m--){
		cin>>x;
		idx = rightBinsearch(0, n-1, x);
		cout << (a[idx]==x?idx+1:0) << '\n';
	}
}