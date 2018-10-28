#include <iostream>

using namespace std;

struct node
{
	int value;
	node * next;
	node * prev;

	node(int x){
		value = x;
		prev = NULL;
		next = NULL;
	}
};

struct LinkedList
{
	public:
		node * head;
		node * tail;

		LinkedList()
		{
			head = NULL;
			tail = NULL;
		}
		
		void insertFirst(int x) {
			node * el = new node(x);

			if(head == NULL && tail == NULL){
				head = el;
				tail = el;
				return;
			}
			else
			{
				el->next = head;
				head->prev = el;
				head = el;
			}
		}
		
		void insertLast(int x) {
			node * el = new node(x);

			if(head == NULL && tail == NULL){
				head = el;
				tail = el;
				return;
			}
			else
			{
				el->prev = tail;
				tail->next = el;
				tail = el;
			}
		}

		void deleteFirst() {
			head = head->next;
			
			if(!head)
			{
				head->prev = NULL;
			}
			else
			{
				tail = NULL;
			}
		}

		void deleteLast() {
			tail = tail->prev;

			if(!tail)
			{
				tail->next = NULL;
			}
			else
			{
				head = NULL;
			}
		}

		void del(int x) {
			node * cur = head;
			while(cur && cur->value != x)
			{
				cur = cur->next;
			}

			if(!cur) return;

			if(cur == head) {
				deleteFirst();
			}
			else if(cur == tail) {
				deleteLast();
			}
			else {
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;
			}
		}

		void print() {
			node * cur = head;
			while(cur) {
				cout << cur->value;
				if(cur != tail) cout << ' ';
				cur = cur->next;
			}
		}

		int count(int x) {
			node * cur = head;
			int cnt = 0;
			while(cur) {
				if(cur->value == x) cnt++;
				cur = cur->next;
			}
			return cnt;
		}

		int getNth(int n) {
			node * cur = head;
			int res = -1, cnt = 0;
			while(cur) {
				if(cnt == n) {
					res = cur->value;
					break;
				}
				cnt++;
				cur = cur->next;
			}
			return res;
		}
		
};

int main()
{
	
	int n, x;
	LinkedList * mylist = new LinkedList();
	string q;
	cin>>n;
	while(n--)
    {
        cin >> q;
        if(q == "insertFirst"){
            cin >> x;
            mylist->insertFirst(x);
        }
        if(q == "insertLast"){
            cin >> x;
            mylist->insertLast(x);
        }
        if(q == "deleteFirst"){
            mylist->deleteFirst();
        }
        if(q == "deleteLast"){
            mylist->deleteLast();
        }
        if(q == "delete"){
        	cin >> x;
        	mylist->del(x);
        }
        if(q == "cnt"){
            cin >> x;
            cout << mylist->count(x) << '\n';
        }
        if(q == "getNth"){
            cin >> x;
            cout << mylist->getNth(x) << '\n';
        }
        
        //cout << mylist->head << ' ' << mylist->tail << '\n';
    }
    mylist->print();
	return 0;
}