#include <iostream>
using namespace std;

int main()
{
    long long inp;
	cin >> inp;
	cout << ((inp%3)?(inp / 2 + 1):(inp / 2)) << endl;
	return 0;
}
