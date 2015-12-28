#include <iostream>
using namespace std;

int main()
{
	int k, result = 0;
	cin >> k;
	if (k == 1)
	{
		cout << 8 << endl;
		return 0;
	}
	// all perfect numbers are in form 11111...11X
	// X = 1
	result ++;
	// X = 2
	if ((k-1) % 3 == 0)
		result ++;
	// X = 3
	// X = 4
	// X = 5
	if ((k-1) % 3 == 0)
		result ++;
	// X = 6
	if ((k-1) % 6 == 0)
		result ++;
	cout << result << endl;
    return 0;
}
