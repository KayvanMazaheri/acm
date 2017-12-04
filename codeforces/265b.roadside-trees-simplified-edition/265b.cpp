#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int result = 0;
	int n, h=0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		result += fabs(h-inp) + 2;
		h = inp;
	}
	cout << result - 1 << endl;
	return 0;
}
