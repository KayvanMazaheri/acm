#include <iostream>
using namespace std;

const int MAXN = 1e4 + 123;

int arr[MAXN];
long long result = 0;

int main()
{
	int n, m;
	cin >> n >> m ;
	for (int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b]++;
	}
	for(int i=0; i<=n; i++)
		result += arr[i] * arr[i];
	cout << result << endl;
	return 0;
}
