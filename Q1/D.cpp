#include <bits/stdc++.h>

#define EPS 1e-10
using namespace std;

double f(double ab,double ac,double bc,double ad)
{
	double ae,de,s1,s2,ltArea,stArea,trapArea, rt;
	ae = (ad*ac)/ab;
	de = (ad*bc)/ab;
	s1 = (ab+ac+bc)/2.0;
	s2 = (ad+ae+de)/2.0;
	ltArea = sqrt(s1 * (s1-ab) * (s1-ac) * (s1-bc));
	stArea = sqrt(s2 * (s2-ad) * (s2-ae) * (s2-de));
	trapArea = ltArea - stArea;
	rt = stArea/trapArea;
	return rt;
}

double binsearch(double l, double r, double ab, double ac, double bc, double rt)
{
    double x = (l + r)/2;
    
    if(fabs(r - l) < EPS) return x;

    if(f(ab, ac, bc, x) > rt) return binsearch(l, x, ab, ac, bc, rt);
    else return binsearch(x, r, ab, ac, bc, rt);
}

void solve()
{
	double ab, ac, bc, rt;
	cin >> ab >> ac >> bc >> rt;
	printf("%.8f\n", binsearch(0, ab, ab, ac, bc, rt));
}
int main()
{
	int t, cs = 0;
	cin>>t;
	while(t--)
	{
		cout << "Case " << ++cs <<": ";
		solve();
	}
}