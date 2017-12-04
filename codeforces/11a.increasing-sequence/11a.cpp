#include <iostream>
using namespace std;

const int MAXN = 2e3 + 123;

int arr[MAXN];

int main()
{
	int n, d;
	cin >> n >> d;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	long long result = 0;
	for(int i=1; i<n; i++)
		if (arr[i] <= arr[i-1])
		{
//			cerr << i << endl;
			int buff = arr[i-1] - arr[i];
			int step = (buff) / d;
			step ++;
//			cerr << step << endl;
			result += step;
			arr[i] += step * d;
		}
	cout << result << endl;
	return 0;
}
