#include <iostream>

using namespace std;

const int MAXN = 1e6;

int bag[MAXN];

int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		sum += inp;
		bag[i] = inp;
	}

	int result = 0;
	for(int i=0; i<n; i++)
		if(bag[i]%2 == sum%2)
			result ++;
	cout << result << endl;
	return 0;
}
