#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 123;

int arr[MAXN];

int main()
{
	int n, d;
	cin >> n >> d;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	long long result = 0;
	for(int i=0; i<n; i++)
	{
		int first = arr[i];
		int last = first + d;
		int last_av = upper_bound(arr, arr+n, last) - arr;
		long long buffer = last_av - i - 1;
		long long num = (buffer * (buffer - 1))/2;
		result += num;
	}
	cout << result << endl;
	return 0;

}
