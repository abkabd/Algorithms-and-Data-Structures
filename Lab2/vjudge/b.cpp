#include <iostream>
#include <queue>

using namespace std;


void solve(int p, int c)
{
	int cur = 1, x, t;
	char ch;
	queue<int> q;
	for(int i=1; i<=min(p, 1000); i++){
		q.push(i);
	}

	while(c--){
		cin>>ch;
		if(ch == 'N'){
			t = q.front();
			cout << t << '\n';
			q.push(t);
			q.pop();
		}
		if(ch == 'E'){
			queue<int> temp;
			cin>>x;
			temp.push(x);
			while(!q.empty()){
				t = q.front();
				if(t != x){
					temp.push(t);
				}
				q.pop();
			}
			q = temp;
		}
	}
}
int main()
{
	int p, c, cs = 1;

	while(true)
	{
		cin>>p>>c;
		if(p==0 && c==0){break;}
		cout << "Case " << cs++ << ":\n";
		solve(p, c);
	}
	return 0;
}