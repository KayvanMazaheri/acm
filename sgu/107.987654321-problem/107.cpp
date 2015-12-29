#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n < 9)
		cout << 0 << endl;
	else if (n == 9)
		cout << 8 << endl;
	else
	{
		int x = n - 10 ;
		cout << 72 ;
		for (int i=0; i<x; i++)
			cout << 0;
		cout << endl;
	}
	return 0;
}
