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
		bool reversed;
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
			reversed = false;
		}
		
		void push_back(int x) {
			if(reversed) {
				reversed = false;
				push_front(x);
				reversed = true;
				return;
			}

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
			if(reversed) {
				reversed = false;
				push_back(x);
				reversed = true;
				return;
			}

			if(empty()){
				push(x);
				return;
			}
			
			node * el = new node(x, NULL, head);
			
			head->prev = el;
			head = el;
			cnt++;
		}
		
		void front() {
			if(reversed) {
				reversed = false;
				back();
				reversed = true;
				return;
			}

			if(!empty()) {
				int res = head->value;
				head = head->next;
				cnt--;
				cout << res;
			}
			else
				cout << ";(";
			cout << '\n';
		}

		void back() {
			if(reversed) {
				reversed = false;
				front();
				reversed = true;
				return;
			}

			if(!empty()) {
				int res = tail->value;
				tail = tail->prev;
				cnt--;
				cout << res;
			}
			else
				cout << ";(";
			cout << '\n';
		}

		void reverse() {
			reversed = !reversed;
		}

		
		bool empty() {
			return cnt == 0;
		}
		
};

int main()
{
	myDeque md;
	string q;
	int n, x;
	cin>>n;
	while(n--)
    {
        cin >> q;
        if(q == "push_back"){
            cin >> x;
            md.push_back(x);
        }
        if(q == "push_front"){
            cin >> x;
            md.push_front(x);
        }
        if(q == "front"){
            md.front();
        }
        if(q == "back"){
            md.back();
        }
        if(q == "reverse"){
            md.reverse();
        }
    }
	return 0;
}