#include <iostream>
using namespace std;

const int MAXN = 1002;

int main()
{
	int m, n;
	cin >> m >> n;
	int result = 0;
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			if (i*i + j == m && j*j + i == n)
				result ++;
	cout << (m == n ? result : result ) << endl;
	return 0;
}
