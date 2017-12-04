#include <iostream>
#include <algorithm>

using namespace std;

long long luckeyMask(long long n)
{
	long long result = 0;
	while (n)
	{
		if (n%10 == 4 || n%10 == 7)
			result = 10 * result + (n % 10);
		n/=10;
	}
	long long Fresult = 0;
	while (result)
	{
		Fresult = 10 * Fresult + (result % 10);
		result/=10;
	}
	return Fresult ;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	//if (a > b)
	{
		for(long long i=a+1; 1; i++)
			if (luckeyMask(i) == b)
			{
				cout << i << endl ;
				break;
			}
	}
	//else
		//cout << b << endl ;
	return 0;
}
