#include <iostream>

using namespace std;

struct node
{
	long long int value;
	node * prev;

	node(long long int x, node * pr){
		value = x;
		prev = pr;
	}
};

struct myStack
{
	private:
		node * top;
		int cnt;



	public:
		myStack()
		{
			top = NULL;
			cnt = 0;
		}

		void push(long long int x) {
			node * el = new node(x, top);
			top = el;
			cnt++;
		}
		
		int pop() {
			int res = top->value;
			if(!empty()) {
				
				top = top->prev;
				cnt--;
			}
			
			
			return res;
		}
		int back() {
			if(!empty())
				return top->value;
		}

		int size() {
			return cnt;
		}
		void clear() {
			top = NULL;
			cnt = 0;
		}
		bool empty() {
			return cnt == 0;
		}
		
};

long long int toInt(string s)
{
	int i = 0;
	long long int res = 0;
	while(i<s.size())
	{
		res *= 10;
		res += int(s[i] - '0');
		
		i++;
	}
	return res;
}
int main()
{
	long long int x, y, res;
	string s;
	myStack st;

	while(cin>>s){
		if(s == "+")
		{
			x = st.back();
			st.pop();
			y = st.back();
			st.pop();
			st.push(x+y);
		}
		else if(s == "-")
		{
			x = st.back();
			st.pop();
			y = st.back();
			st.pop();
			st.push(y-x);
		}
		else if(s == "*")
		{
			x = st.back();
			st.pop();
			y = st.back();
			st.pop();
			st.push(x*y);
		}
		else
		{
			st.push(toInt(s));
		}
	}

	cout << st.back() << endl;
	return 0;
}