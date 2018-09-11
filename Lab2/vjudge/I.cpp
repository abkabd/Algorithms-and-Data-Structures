#include <iostream>
#include <queue>

#define ll long long
#define mp make_pair
#define F first
#define S second

using namespace std;

queue<pair<string, int> > mq;
queue<pair<string, int> > ans;
int main()
{
	ll n, q, t, time=0; 
	string s;
	
	cin>>n>>q;
	while(n--)
	{
		cin>>s>>t;
		mq.push(mp(s, t));
	}


	while(!mq.empty())
	{
		if(mq.front().S - q <= 0)
		{
			time += mq.front().S;
			ans.push(mp(mq.front().F, time));
			mq.pop();
		}
		else{
			time += q;
			mq.front().S -= q;
			mq.push(mq.front());
			mq.pop();
		}
		
		
	}


	while(!ans.empty())
	{

		cout << ans.front().F << ' ' << ans.front().S << endl;
		ans.pop();
	}
	
	return 0;
}