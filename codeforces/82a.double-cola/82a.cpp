#include <iostream>
#include <string>

using namespace std;

string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
	long long n;
	cin >> n ;
	int f = 5;
	while (n > f)
	{
		n -= f;
		f *= 2;
	}
	f /= 5;
	cerr << f << " " << n << endl;
	int pos = ((n+f-1) / f)-1;
	cerr << pos << endl;
	cout << names[pos] << endl;
	return 0;
}
