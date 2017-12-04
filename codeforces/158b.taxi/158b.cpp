#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 123;

int arr[5];

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int inp;
        cin >> inp;
        arr[inp] ++;
    }
	int result = 0;
	result += arr[4];
	int min_1_3 = min (arr[1], arr[3]);
	result += min_1_3;
	arr[3] -= min_1_3;
	arr[1] -= min_1_3;
	result += arr[3];
	result += arr[2] / 2;
	arr[2] = arr[2] % 2;
	if (arr[2])
	{
		result ++;
		arr[1] -= 2;
	}
	if (arr[1] > 0)
	{
		result += arr[1]/4;
		if (arr[1] % 4)
			result ++;
	}
	cout << result << endl;
	return 0;
}
