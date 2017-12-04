#include <iostream>

using namespace std;

bool arr[200];

int main()
{
	int n, X, Y;
	cin >> n;
	cin >> X;
	for (int i = 0; i < X; ++i)
	{
		int inp;
		cin >> inp;
		arr[inp-1] = true;
	}

	cin >> Y;
	for (int i = 0; i < Y; ++i)
	{
		int inp;
		cin >> inp;
		arr[inp-1] = true;
	}

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		res+=arr[i];
	}

	cout << ( res == n ? "I become the guy." : "Oh, my keyboard!") << endl;
	return 0;
}