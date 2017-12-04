#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 123;

long long arr[20 + 5];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		arr[inp+10] ++;
	}

	unsigned long long result = 0;
	for(int i=0; i<10; i++)
		result += (arr[i]* arr[20-i]);
	result += ((arr[10] * (arr[10] -1)) / 2);
	cout << result << endl;
	return 0;
}
