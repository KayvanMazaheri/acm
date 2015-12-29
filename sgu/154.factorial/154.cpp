#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int q;
	cin >> q;
	double time = 0;
	//for (q=0; q<2e2 + 4; q++)
	{
	int n=0;
	int i= 0;
	int l = 0;

	if (q >= 9e7)
	{
		i = 360000015 / 5 ;
		n = 9e7 ;
	}
	else if (q >= 8e7)
	{
		i = 320000015 / 5 ;
		n = 8e7 ;
	}
	else if (q >= 7e7)
	{
		i = 280000015 / 5 ;
		n = 7e7 ;
	}
	else if (q >= 6e7)
	{
		i = 240000020 / 5 ;
		n = 6e7 ;
	}
	else if (q >= 5e7)
	{
		i = 200000010 / 5 ;
		n = 5e7 ;
	}
	else if (q >= 4e7)
	{
		i = 160000015 / 5 ;
		n = 4e7 ;
	}
	else if (q >= 3e7)
	{
		i = 120000010 / 5 ;
		n = 3e7 ;
	}
	else if (q >= 2e7)
	{
		i = 80000015 / 5 ;
		n = 2e7 ;
	}
	else if (q >= 1e7)
	{
		i = 40000010 / 5 ;
		n = 1e7 ;
	}


	while(n < q)
	{
		i++;
		n++;
		l = i;

		while (l%5 == 0 && l>0)
		{
			n++;
			l/=5;
		}
	}
	//cout << q << " =  " ;
	if (i == 0)
		cout << 1 << endl ;
	else if (n > q)
		cout << "No solution" << endl ;
	else
		cout << (5 * i)  << endl ;

	//time = (double)clock() / CLOCKS_PER_SEC - time;
	//cerr << time << endl;
	}
	return 0;
}
