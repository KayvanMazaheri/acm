#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1e2 + 123;

int point[MAXN];

int winner (int a, int b, int x, int y)
{
	if (a > b && x > y)
		return 2;
	if (a == b && x == y)
		return 2;
	if (a < b && x < y)
		return 2;
	return 0;
}

int diff(int a, int b, int x, int y)
{
	if (x-y == a-b)
		return 3;
	return 0;
}

int goals(int a, int x)
{
	if (a == x)
		return 1;
	return 0;
}


int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		int x, y;
		for(int j=0; j<n; j++)
		{
			cin >> x >> y;
			point[j] += (goals(a, x) + goals(b, y) + diff(a, b, x, y) + winner(a, b, x, y));
		}
	}
	for(int i=0; i<n; i++)
		cout << point[i] << " ";
	cout << endl;
	return 0;

}
