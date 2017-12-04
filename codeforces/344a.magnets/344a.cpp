#include <iostream>
using namespace std;

const int MAXN = 1e5 + 123;

int magnet[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> magnet[i];
	int groups = 1;
	for(int i=1; i<n; i++)
		if (magnet[i] != magnet [i-1])
			groups ++;

	cout << groups << endl;
	return 0;

}
