#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

int main()
{
	int x, y, res;
	string s;
	getline(cin, s);
	for(int i=0; i<s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			st.push(s[i] - '0');
		}
		if(s[i] == '+')
		{
			x = st.top();
			st.pop();
			y = st.top();
			st.pop();
			st.push(x+y);
		}
		if(s[i] == '-')
		{
			x = st.top();
			st.pop();
			y = st.top();
			st.pop();
			st.push(y-x);
		}
		if(s[i] == '*')2                                                       
		{
			x = st.top();
			st.pop();
			y = st.top();
			st.pop();
			st.push(x*y);
		}
	}

	cout << st.top();
	return 0;
}