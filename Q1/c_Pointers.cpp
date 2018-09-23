#include <iostream>
using namespace std;

struct node
{
	int value;
	node * next;
	node * prev;

	node(int x, node * pr, node * nx){
		value = x;
		prev = pr;
		next = nx;
	}
};

struct myDeque
{
	private:
		node * head;
		node * tail;
		int cnt;
		void push(int x) {
			node * el = new node(x, NULL, NULL);
			head = el;
			tail = el;
			cnt++;
		}

	public:
		myDeque()
		{
			head = NULL;
			tail = NULL;
			cnt = 0;
		}
		
		void push_back(int x) {
			if(empty()){
				push(x);
				return;
			}
			
			node * el = new node(x, tail, NULL);

			tail->next = el;
			tail = el;
			cnt++;
		}

		void push_front(int x) {
			if(empty()){
				push(x);
				return;
			}
			
			node * el = new node(x, NULL, head);
			
			head->prev = el;
			head = el;
			cnt++;
		}
		
		void pop_back() {
			if(!empty()) {
				int res = tail->value;
				tail = tail->prev;
				cnt--;
			}

		}

		void pop_front() {
			if(!empty()) {
				int res = head->value;
				head = head->next;
				cnt--;
			}

		}
		int front() {
			if(!empty())
				return head->value;
		}

		int back() {
			if(!empty())
				return tail->value;
		}

		int size() {
			return cnt;
		}
		void clear() {
			head = NULL;
			tail = NULL;
			cnt = 0;
		}
		bool empty() {
			return cnt == 0;
		}
		
};

void solve()
{
	myDeque d;
	d.clear();
	int n, m, x;
	string s;
	cin >> n >> m;
	while(m--){
		cin >> s;
		if(s == "pushLeft"){
			cin >> x;
			if(d.size() == n){
				cout << "The queue is full\n";
			}
			else {
				d.push_front(x);
				cout << "Pushed in left: " << x << "\n";
			}
		}
		if(s == "pushRight"){
			cin >> x;
			if(d.size() == n){
				cout << "The queue is full\n";
			}
			else {
				d.push_back(x);
				cout << "Pushed in right: " << x << "\n";
			}
		}
		if(s == "popLeft"){
			if(d.empty()){
				cout << "The queue is empty\n";
			}
			else {
				x = d.front();
				d.pop_front();
				cout << "Popped from left: " << x << "\n";
			}
		}
		if(s == "popRight"){
			if(d.empty()){
				cout << "The queue is empty\n";
			}
			else {
				x = d.back();
				d.pop_back();
				cout << "Popped from right: " << x << "\n";
			}
		}
	}
}
int main()
{
	int t, cs = 0;
	cin>>t;
	while(t--)
	{
		cs++;
		cout << "Case " << cs << ":\n";
		solve();
	}
}