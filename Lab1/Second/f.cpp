#include <iostream>
#include <vector>
#include <pair>

#define pop push_back
#define pp pop_back
#define mp make_pair

using namespace std;

vector<vector<int> >v;
vector<pair<int, int> >ans;

bool check(int el, int y)
{
	for(int i = 0; i < v[y].size(); i++)
	{
		if(v[y][i] != el)
			return false;
	}
	return true;
}

void put1(int x, int y)
{
	if(check(v[x].back(), y))
	{
		cout << x+1 << ' ' << y+1 << '\n';
		v[y].push_back(v[x].back());
		v[x].pop_back();
	}
	else
	{
		cout << x+1 << ' ' << 1 << '\n';
		v[0].push_back(v[x].back());
		v[x].pop_back();
	}
}

void put2(int x, int y)
{
}

int main()
{
	int n, k, x, res;
	cin>>n;
	res = n-1;

	for(int i=0; i<n; i++)
	{
		vector<int> t;
		cin>>k;
		for(int j=0; j<k; j++)
		{
			cin>>x;
			t.push_back(x);
		}

		v.push_back(t);
	}

	for(int i=0; i<n; i++)
	{
		cout << i+1 << ": ";
		for(int j=0; j<v[i].size(); j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}

	for(int i=1; i<n; i++)
	{
		while(!v[i].empty())
		{
			int el= v[i].back();
			v[i].pop_back();

			if(check(el, el-1))
			{
				if(i+1 == el)
					continue;
				cout << i+1 << ' ' << el << '\n';
				v[el-1].push_back(el);
			}
			else
			{
				cout << i+1 << ' ' << 1 << '\n';
				v[0].push_back(el);
			}
			for(int i =0; i<10e8; i++){}
		}
	}

	for(int i=0; i<n; i++)
	{
		cout << i+1 << ": ";
		for(int j=0; j<v[i].size(); j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
	
	while(!v[0].empty())
	{
		int el = v[0].back();
		v[0].pop_back();
		if(el != 1)
		{

		}
		else
		{
			v[res].
		}
	}
	return 0;
}