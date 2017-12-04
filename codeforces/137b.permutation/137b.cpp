#include <iostream>

using namespace std;

const int MAXN = 5e3 + 123;

bool mark [MAXN];

int main()
{
	int n, total = 0;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		if(!mark[inp] && inp <=n && inp > 0)
		{
			mark[inp]= true;
			total ++;
		}
	}
	cout << n-total << endl;
	return 0;
}
