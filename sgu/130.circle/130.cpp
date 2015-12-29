#include <iostream>
using namespace std;

long long da[50];

long long f(int n)
{
	long long  result = 0;
	int l = n-2 ;
	for (int i=l; i>=0; i-=2)
	{
		result += da[i/2] * da[(l-i)/2];
	}
	return result ;
}
int main()
{
	da[0] = 1;
	long long n, k, p;
	cin >> k;
	n = 1;
	for (int i=1; i<=k; i++)
	{
		da[i] = f(i*2) ;
	}
	p= k+1;
	cout << da[k] << " " << p << endl;
	return 0;
}
