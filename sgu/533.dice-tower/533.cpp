#include <iostream>
using namespace std;

int main()
{
    long long n = 0;
	cin >> n;
	long long sides = n / 14;
	long long up_down = n%14;
	long long dices = 0;
	dices = sides;
	if (dices == 0 || up_down == 1 || up_down == 13 || up_down == 0 || n<21 || (dices == 1 && n > 21))
		dices = -1;
	cout << dices << endl;
	return 0;
}
