#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k ;
	long long sum = 2;
	int a,b,c;
	a=1;
	b=1;
	c=0;
	if (k<3)
	{
		cout << k ;
		return 0;
	}
	for (int i=2; i<k; i++)
	{
		c=a+b ;
		a=b;
		b=c;
		sum += c;

	}
	cout << sum ;
	return 0;
}
