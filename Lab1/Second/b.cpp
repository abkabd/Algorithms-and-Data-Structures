#include <iostream>
#include <queue>

using namespace std;
queue<int> f, s;

int main()
{
	int st = 0, x;
	bool stop = false;

	for(int i=0; i<5; i++){
		cin >> x;
		f.push(x);
	}
	for(int i=0; i<5; i++){
		cin >> x;
		s.push(x);
	}

	while(!stop)
	{
		if(f.front() > s.front())
		{
			if(f.front() == 9 && s.front() == 0)
			{
				s.push(f.front());
				s.push(s.front());
			}
			else{
				f.push(f.front());
				f.push(s.front());
			}
		}

		if(s.front() > f.front())
		{
			if(f.front() == 0 && s.front() == 9)
			{
				f.push(f.front());
				f.push(s.front());
			}
			else{
				s.push(f.front());
				s.push(s.front());
			}
		}

		st++;
		f.pop();
		s.pop();

		if(f.empty())
		{
			cout << "second " << st;
			stop = true;
		}

		if(s.empty())
		{
			cout << "first " << st;
			stop = true;
		}

		if(st > 1000000)
		{
			cout << "botva";
			stop = true;
		}
	}
	return 0;
	
}