// In the name of God
// :)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1e9;
int n;

bool isLess(string f, string s)
{
	bool mark[n];
	fill (mark, mark+n, 0);
	sort(f.begin(), f.end());
	sort(s.begin(), s.end());
	for(int i=0; i<n; i++)
	{
		bool bad = true;
		for(int j=0; j<n; j++)
		{
			if (f[i] < s[j] && !mark[j])
			{
				mark[j] = true;
				bad = false;
				break;
			}
		}
		if (bad)
			return false;
	}
	return true;
}


int main()
{
	string inp;
	cin >> n >> inp;
	string f = inp.substr(0, n);
	string s = inp.substr(n, n);

	if (isLess(f, s) || isLess(s, f))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
