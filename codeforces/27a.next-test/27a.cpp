#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 3e3 + 123;

int arr[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	int result;
	for(result = 1; result <= n && arr[result - 1] == result; result++);
	cout << result << endl;
	return 0;
}
