#include <iostream>
#include<queue>
#include<deque>
using namespace std;

queue<char> back;
deque<char> front;

int main()
{
	int n;
	string s;
	bool ok = true;
	while(cin >> s)
	{
		for(int i=0; i<s.size(); i++)
		{
			if(s[i] == '[' || s[i] == ']'){
				ok = !ok;
				continue;
			}

			if(ok){
				back.push(s[i]);
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
			back.pop();
		}
		cout << '\n';
	}
	return 0;
}