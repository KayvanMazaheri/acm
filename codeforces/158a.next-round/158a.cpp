#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int arr[MAXN];

void reverse(int n)
{
	for(int i=0; i<=n/2; i++)
		swap(arr[i], arr[n-i]);
}

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	sort(arr, arr+n);
	reverse(n-1);
	for(int i=0; i<n; i++)
		cerr << arr[i] << " ";
	cerr << endl;
	int result = 0;
	for (int i=0; i<k && arr[i]; i++)
		result ++;
	for(int i=k; i<n && arr[i] && arr[i] == arr[k-1]; i++)
		result ++;
	cout << result << endl;
	return 0;
}
