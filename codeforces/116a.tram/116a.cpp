#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cap = 0;
	int max_cap = 0;
	for (int i=0; i<n; i++)
	{
		int exit, enter ;
		cin >> exit >> enter ;
		cap -= exit ;
		cap += enter ;
		if (cap > max_cap)
			max_cap = cap ;
	}
	cout << max_cap << endl ;
	return 0;
}
