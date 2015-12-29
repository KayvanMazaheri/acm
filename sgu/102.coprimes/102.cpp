#include <iostream>
using namespace std;

int gcd(int n,int m)
{
	if (n<m)
		swap(n,m);
	int r=m;
	while (r!=0)
	{
		m=r;
		r=n%m;
		n=m;

	}
	return n;
}
int main()
{
	int n;
	cin >> n ;
	int sum = 0;
	for(int i=1; i<=n; i++)
		if (gcd(n,i)==1)
			sum++;
	cout << sum;
}
