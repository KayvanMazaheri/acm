#include <iostream>
using namespace std;

int main()
{
	long long s;
	long long p;
	cin >> s >> p ;
	if (p>s)
	{
		long long result = 0 ;
		result = p-s  ;
		if ((result>=1)&&(result<5*60))
			cout << 1;
		if ((result>=5*60)&&(result<15*60))
			cout << 2;
		if ((result>=15*60)&&(result<30*60))
			cout << 3;
		if ((result>=30*60))
			cout << 4;



	}
	else
		cout << 0 ;
	return 0;
}
