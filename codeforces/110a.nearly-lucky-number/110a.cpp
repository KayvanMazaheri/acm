#include <iostream>
using namespace std;

bool isLucky(int x)
{
	if(x/10 > 0)
		return (isLucky(x/10) && isLucky(x%10));
	if (x == 7 || x == 4)
		return true ;
	return false ;

}
int main()
{
	long long n;
	cin >> n;
	int luckyDigits = 0;
	while(n>0)
	{
		if (isLucky(n%10))
			luckyDigits ++ ;
		n/=10;
		//cerr << n << " " ;
	}
	//cerr << luckyDigits << endl;
	if (isLucky(luckyDigits))
		cout << "YES" << endl ;
	else
		cout << "NO" << endl ;

	return 0;

}
