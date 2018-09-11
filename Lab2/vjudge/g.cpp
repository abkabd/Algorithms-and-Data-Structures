#include <iostream>
#include <deque>


using namespace std;

deque<int> dq;
deque<int>::iterator it;
int main()
{
	int n, x;
	string s;
	
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(s == "insert")
		{
			cin>>x;
			dq.push_front(x);
		}
		if(s == "delete")
		{
			cin>>x;
			for(it = dq.begin(); it != dq.end(); it++)
			{
				if(*it == x)
				{
					dq.erase(it);
					break;
				}
			}
		}
		if(s == "deleteFirst")
		{
			dq.pop_front();
		}
		if(s == "deleteLast")
		{
			dq.pop_back();	
		}
	}
	
	while(!dq.empty())
	{
		cout << dq.front();
		dq.pop_front();
		if(dq.size()>0)cout << ' ';
	}
	cout << '\n';

	return 0;
}