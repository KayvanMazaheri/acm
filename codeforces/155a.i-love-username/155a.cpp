#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int minimum = 1e5 + 321 ;
	int maximum = -1;
	int inp, amazing = 0;
	for(int i=0; i<n; i++)
	{
		cin >> inp;
		if(inp > maximum)
		{
			maximum = inp;
			amazing ++;
		}
		if(inp < minimum)
		{
			minimum = inp;
			amazing ++;
		}
	}

	cout << amazing -2 << endl;
	return 0;
}
