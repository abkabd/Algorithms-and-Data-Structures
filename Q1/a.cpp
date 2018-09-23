#include <iostream>
#include <stack>
using namespace std;

void solve()
{
	stack <char> st;
	string s;
	cin >> s;

	for(int i = 0; i<s.size(); i++){
		if(!st.empty())
		{
			if(st.top() == '(' && s[i] == ')')
			{
				st.pop();
			}
			else if(st.top() == '[' && s[i] == ']')
			{
				st.pop();
			}
			else if(st.top() == '{' && s[i] == '}')
			{
				st.pop();
			}
			else
			{
				st.push(s[i]);
			}
		}
		else
		{
			st.push(s[i]);
		}
	}

	cout << (st.empty() ? "YES" : "NO") << '\n';

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
}