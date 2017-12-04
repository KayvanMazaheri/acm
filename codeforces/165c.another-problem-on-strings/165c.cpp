#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 1e6 + 123;

int arr[MAX_N];
int dp[MAX_N];

int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	int n = s.size();
	for(int i=0; i<n; i++)
	{
		arr[i] = s[i] - '0';
		dp[i] = (i ? dp[i-1] : 0) + arr[i];
	}
	long long result = 0;
	for(int i=0; i<n; i++)
	{
		int up = (upper_bound(dp, dp+n, dp[i] + k - arr[i]) - dp);
		int low = (lower_bound(dp + i, dp+n, dp[i] + k - arr[i]) - dp);
		if (low < i)
			continue;
		//cerr <<i << " : " << low << " " << up << endl;
		result += up - low;
	}

	cout << result << endl;
	return 0;
}
