#include <iostream>

using namespace std;

const int MAXN = 2e2 + 21;

int arr[MAXN];

int main()
{
	int n, a, b, result = 0;
	cin >> n;
	for(int i=1; i<n; i++)
		cin >> arr[i];
	cin >> a >> b;
	for(int i=a; i<b; i++)
		result += arr[i];
	cout << result << endl;
	return 0;
}
