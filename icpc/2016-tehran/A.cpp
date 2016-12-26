#include <iostream>
using namespace std;

int main()
{
	int n;
	while(true){
		cin >> n;
		if (!n)
			break;
		int tax = 0;
		if (n > 1000000)
			tax = n / 10;
		if (n > 5000000)
			tax = (2 * n) / 10;

		cout << n - tax << endl;
	}
	return 0;
}