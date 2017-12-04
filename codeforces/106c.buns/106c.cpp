#include <iostream>
using namespace std;

const int MAX_N = 1e3 + 123;

int dp[MAX_N][MAX_N];

int a[MAX_N];
int b[MAX_N];
int c[MAX_N];
int d[MAX_N];


int main()
{
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	a[0] = n;
	b[0] = c0;
	c[0] = c0;
	d[0] = d0;
	for(int i=1; i<=m; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=m; j++)
		{
			int max_one = a[j] / b[j];
			int mx = -1;
			for(int k=0; k<=max_one; k++)
			{
				int need =c[j] * k;
				if (need > i)
					break;
				int buff = (d[j] * k) + dp[i-need][j-1];
				mx = max(mx, buff);
			}
			dp[i][j] = mx;
		}
	}
	cout << dp[n][m] << endl;


}
