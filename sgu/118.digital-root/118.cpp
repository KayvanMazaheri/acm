#include <iostream>
using namespace std;

long long f(long long n)
{
    long long result = n%10;
	for(long long i=0; n/10; i++)
	{
		n/=10;
		result += n%10;
	}
	return (result/10)?(f(result)):result;
}

int main()
{
	long long k;
	cin >> k;
	for(int t=0; t<k; t++)
	{
		int n;
		cin >> n;
		long long result = 0;
		long long last_f = 1;
		for(int i=0; i<n; i++)
		{
			long long a;
			cin >> a;
			last_f = f(a*last_f);
			result += last_f;
		}
		result = f(result);
		cout << result << endl;

	}
}
