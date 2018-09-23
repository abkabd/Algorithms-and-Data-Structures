#include <iostream>
#include <cmath>

using namespace std;

int rec(int n)
{
	if(n == 0) return 0;

	
	int c = n;
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0)
		{
			c = min(c, rec(n/i)+1);
		}
	}
	return min(c, rec(c-1)) + 1;
}

void solve()
{
	int n;
	cin >> n;
	cout << rec(n) << "\n";
}
int main()
{
	int t, cs = 0;
	cin>>t;
	while(t--)
	{
		solve();
	}
}