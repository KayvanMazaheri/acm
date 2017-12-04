// In the name of God
// :)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 1e2 + 123;

int arr[MAXN];

int main()
{
	int n, sum =0, me = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr+n);
	int coins = 0;
	for(int i=n-1; i>=0 && me <= sum; i--)
	{
		coins ++;
		me+= arr[i];
		sum -= arr[i];
	}
	cout << coins << endl;
	return 0;
}
