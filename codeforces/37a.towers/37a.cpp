#include <iostream>
using namespace std;

const int MAXN = 1e3 + 12;

bool mark[MAXN];
int bar[MAXN];

int main()
{
	int n, max = 0, num = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		if (!mark[inp])
			num++;
		mark[inp] = true;
		bar[inp]++;
		if(bar[inp] > max)
			max = bar[inp];
	}
	cout << max << " " << num << endl;
	return 0;
}
