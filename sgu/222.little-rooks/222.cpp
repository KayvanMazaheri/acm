#include <iostream>
using namespace std;

int main()
{
	int k,n;
	cin >> n >> k ;
	unsigned long long ways = 1;
	unsigned long long free = n*n ;
	if (k>n)
	{
		cout << 0;
		return 0;
	}

	for(int i=0; i<k; i++)
	{
		ways *= free;
		free -= 2*n;
		free ++ ;
		free += 2*i;
		if (free < 0)
			free = 0;
	}
	unsigned long long ezafe = 1;
	for(int i=1; i<=k; i++)
		ezafe*=i;
	cout << ways/ezafe ;
	return 0;
}
