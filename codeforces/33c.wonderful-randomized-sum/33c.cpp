#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e5 + 123;

int arr[MAXN];

pair <int, int> dp_right[MAXN];
pair <int, int> dp_left[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> arr[i];
	dp_left[0] = make_pair(0, 0);
	dp_right[n+1] = make_pair(0, 0);
	for(int i=1; i<=n; i++)
	{
		dp_left[i].X = dp_left[i-1].X + arr[i];
		dp_left[i].Y = min(dp_left[i].X, dp_left[i-1].Y);
	}
	for(int i=n; i; i--)
	{
		dp_right[i].X = dp_right[i+1].X + arr[i];
		dp_right[i].Y = min(dp_right[i].X, dp_right[i+1].Y);
	}
	int res_pos = 1;
	for(int i=1; i<n; i++)
		if (dp_right[i+1].Y + dp_left[i].Y < dp_right[res_pos+1].Y + dp_left[res_pos].Y)
			res_pos = i;
	cerr << res_pos << endl;
	cerr << dp_left[res_pos].X << " " << dp_left[res_pos].Y << endl;
	cerr << dp_right[res_pos+1].X << " " << dp_right[res_pos+1].Y << endl;
	int result = dp_right[res_pos+1].X + dp_left[res_pos].X  ;
	cerr << result << endl;
	int remain = result - (dp_right[res_pos+1].Y + dp_left[res_pos].Y);
	cerr << remain << endl;
	result = remain + (-1 *(dp_right[res_pos+1].Y + dp_left[res_pos].Y));
	cout << result << endl;
	return 0;


}
