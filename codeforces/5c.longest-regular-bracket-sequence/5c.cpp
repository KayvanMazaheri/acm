#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 1e6 + 123;

int dp[MAX_N];

int main()
{
	string s;
	cin >> s;
	for(int i=1; i<s.size(); i++)
		if (s[i] == ')')
		{
			if (s[i-1] == '(')
				dp[i] = dp[i-2] + 2;
			else if (s[i - 1 - dp[i-1]] == '(')
				dp[i] = dp[i - 2 - dp[i-1]] + dp[i-1] + 2  ;
		}
	sort(dp, dp+MAX_N, std::greater<int>());
	int num = upper_bound(dp, dp+MAX_N, dp[0], std::greater<int>()) - dp;
	cout << dp[0] << " " << (dp[0] ? num : 1) << endl;
	return 0;
}
