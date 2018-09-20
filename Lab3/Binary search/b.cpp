#include <iostream>

using namespace std;

int main()
{
	int n, x = 1, cnt=0;
	cin>>n;
	while(x < n){
		x *= 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}


