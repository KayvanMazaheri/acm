#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 1e5 + 123;
const int INF = 9e9;

int arr[MAX_N];
int dp_right[MAX_N];
int dp_left[MAX_N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<n; i++)
		dp_left[i] = dp_left[i-1] + (arr[i] >= 0);
	for(int i=n-1; i >= 0; i--)
		dp_right[i] = dp_right[i+1] + (arr[i] <= 0);

	int result = INF;
	for(int i=0; i<n-1; i++)
		result = min(result, dp_left[i] + dp_right[i+1]);
	cout << result << endl;
	return 0;
}
