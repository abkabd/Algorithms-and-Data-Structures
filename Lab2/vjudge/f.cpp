#include <iostream>
#include<queue>
#include<deque>
using namespace std;

deque<char> back;
deque<char> front;

int main()
{
	int n;
	string s, t;
	bool ok = true;
	while(cin >> s)
	{
		s += "]";
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == '['){
				ok = false;
				while(!front.empty())
				{
					t += front.back();
					back.push_front(front.back());
					front.pop_back();
				}
				continue;
			}
			if(s[i] == ']'){
				ok = true;
				while(!front.empty())
				{
					t += front.back();
					back.push_front(front.back());
					front.pop_back();
				}
				continue;
			}

			if(ok){
				back.push_back(s[i]);
			}
			else{
				front.push_back(s[i]);
			}

		}

		while(!front.empty())
		{
			cout << front.front();
			front.pop_front();
		}

		while(!back.empty())
		{
			cout << back.front();
			back.pop_front();
		}
		cout << '\n';
	}
	return 0;
}