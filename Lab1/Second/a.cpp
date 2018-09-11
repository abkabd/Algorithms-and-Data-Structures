#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<string> > mp;
map<int, vector<string> >::iterator it;

int main()
{
	int n;
	string s;
	while(cin >> n >> s)
	{
		mp[n].push_back(s);
	}

	for(it = mp.begin(); it != mp.end(); ++it){
		for(int i = 0; i < it->second.size(); i++){
			cout << it->first << ' ' << it->second[i] << '\n';
		}
	}
	return 0;
}