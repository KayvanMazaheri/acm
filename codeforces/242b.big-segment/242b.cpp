#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e5 + 123;

pair<int, int> arr [MAXN];


int main()
{
	int min_l = 1e9 + 2;
	int max_r = -1e9 - 2;

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i].X >> arr[i].Y;
		min_l = min(min_l, arr[i].X);
		max_r = max(max_r, arr[i].Y);
	}
	//cerr << min_l << " " << max_r << endl;
	for(int i=0; i<n; i++)
		if (arr[i].X <= min_l && arr[i].Y >= max_r)
		{
			cout << i+1 << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}
