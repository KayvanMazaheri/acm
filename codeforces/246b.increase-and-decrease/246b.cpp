#include <iostream>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		sum += inp;
	}
	cout << (sum % n ? n-1 : n) << endl;
	return 0;
}
