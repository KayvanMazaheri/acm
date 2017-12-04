#include <iostream>

using namespace std;

const int MAXN = 1e2 + 12;

int arr[MAXN];

int main()
{
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		arr[inp]++;
	}

	long long result = 0;
	for(int i=0; i<MAXN; i++)
		result += (arr[i] / 2);
	result /= 2;
	cout << result << endl;
	return 0;
}
