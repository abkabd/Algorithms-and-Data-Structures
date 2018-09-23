#include <bits/stdc++.h>

using namespace std;

stack<int> a, b;
int pr[2000];

bool isPrime(int n){
	if(n < 2) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

void init()
{
	int MAX_PRIME = 9733;
	int k = 1;
	pr[1] = 2;
	for (int i = 3; i <= MAX_PRIME; i++) {
		bool ok = true;
		for (int j = 2; j <= (int)sqrt(i); j++) {
			if (i % j == 0)
				ok = false;
			}

		if (ok)
		{
			k++;
			pr[k] = i;
		}
	}

}

void solve(int i)
{
	int x;
	stack<int> a0;

	while(!a.empty())
	{
		x = a.top();
		a.pop();
		if(x % pr[i] == 0)
		{
			b.push(x);
		}
		else
		{
			a0.push(x);
		}
	}

	while(!b.empty())
	{
		cout << b.top() << '\n';
		b.pop();
	}

	a = a0;
}

int main()
{
	int n, t, x, i=1;
	init();
	cin>>n>>t;
	for(int i=0; i<n; i++){
		cin>>x;
		a.push(x);
	}
	while(t--)
	{
		solve(i++);
	}
	while(!a.empty())
	{
		cout << a.top() << '\n';
		a.pop();
	}
}