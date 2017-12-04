#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e2 + 123;

int tv[MAXN];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> tv[i];
	sort(tv, tv+n);

	int maxEarn = 0;
	for(int i=0; i<m; i++)
		if (tv[i] <= 0)
			maxEarn -= tv[i];
	cout << maxEarn << endl ;
	return 0;

}
