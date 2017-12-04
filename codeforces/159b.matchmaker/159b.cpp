// In the name of God
// :)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define ll long long
#define point pair <int, int>
#define X first
#define Y second
#define EPS 1e-8
#define MAXN int(1e5 + 123)
#define MAXINP int (1e3 + 123)

using namespace std;

int marker[MAXINP][MAXINP];
int cap[MAXINP][MAXINP];
int n, m, result, BUT;

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		int color, sz;
		cin >> color >> sz;
		marker[sz][0] ++;
		marker[sz][color] ++;
	}
	for(int i=0; i<m; i++)
	{
		int color, sz;
		cin >> color >> sz;
		cap[sz][0] ++;
		cap[sz][color] ++;
	}
	for(int i=0; i<MAXINP; i++)
		result += min(marker[i][0], cap[i][0]);
	for(int i=1; i<MAXINP; i++)
		for(int j=1; j<MAXINP; j++)
			BUT += min(marker[i][j], cap[i][j]);
	cout << result << " " << BUT << endl;
	return 0;
}

