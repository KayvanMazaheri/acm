#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n < 4)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if(n % 4 == 0) // 4
	{
		cout << "1 * 2 = 2" << endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		


	}
	else if (n % 4 == 1) // 5
	{
		cout << "5 * 4 = 20" << endl;
		cout << "3 - 1 = 2" << endl;
		cout << "2 + 2 = 4" << endl;
		cout << "4 + 20 = 24" << endl;



	}
	else if(n % 4 == 2) // 6
	{
		cout << "6 * 4 = 24" << endl;
		cout << "2 + 3 = 5" << endl;
		cout << "5 - 5 = 0" << endl;
		cout << "0 + 1 = 1" << endl;
		cout << "1 * 24 = 24" << endl;

	}
	else // 7
	{
		cout << "6 * 4 = 24" << endl;
		cout << "7 - 5 = 2" << endl;
		cout << "2 + 2 = 4" << endl;
		cout << "3 + 1 = 4" << endl;
		cout << "4 - 4 = 0" << endl;
		cout << "24 + 0 = 24" << endl;

	}

	for (int i = 5 + (n%4); i <= n-3; i+=4)
	{
		cout << i+1 << " - " << i <<  " = " << "1" << endl;
		cout << i+2 << " - " << i+3 <<  " = " << "-1" << endl;
	}
	for (int i = 0; i < (n - (4 + n%4)) / 4; ++i)
	{
		cout << "-1 + 1 = 0" << endl;
	}

	for (int i = 0; i < (n - (4 + n%4)) / 4; ++i)
	{
		cout << "0 + 24 = 24" << endl;
	}

	return 0;

}