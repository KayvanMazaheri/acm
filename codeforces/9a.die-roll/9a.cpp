#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int y, w;
	cin >> y >> w;
	int m = max(y, w);
	int chance = 6 - m + 1;
	int b = 6;
	if (! (chance % 2))
	{
		chance /= 2;
		b /=2;
	}
	if (!(chance % 3))
	{
		chance /= 3;
		b /= 3;
	}
	cout << chance << '/' << b << endl;
	return 0;
}
