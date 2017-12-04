#include <iostream>
#include <string>
using namespace std;

const int MAXN = 1e2 + 123;

string flag[MAXN];
int n, m;

bool check()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (flag[i][j] != flag[i][0])
				return false;
	for(int i=1; i<n; i++)
		if (flag[i][0] == flag[i-1][0])
			return false;
	return true;
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> flag[i];
	cout << (check() ? "YES" : "NO") << endl;
	return 0;
}
