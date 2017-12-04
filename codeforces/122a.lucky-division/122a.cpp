#include <iostream>

using namespace std;

bool isLucky(int x)
{
	while(x)
	{
		if(!(x%10 == 4 || x%10 == 7))
			return false ;
		x/=10;
	}

	return true ;
}

bool isAlmostLucky(int x)
{
	for(int i=2; i<=x; i++)
		if (!(x%i))
			if (isLucky(i))
				return true ;
	return false ;
}
int main()
{
	int n;
	cin >> n;
	//cerr << isLucky(n) << endl ;
	if(isAlmostLucky(n))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
