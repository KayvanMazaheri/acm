#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

pair <int, int> a, b;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		(t == 1 ? a : b).X += x;
		(t == 1 ? a : b).Y += y;
	}
	cout << (a.X >= (a.X + a.Y + 1) / 2 ? "LIVE" : "DEAD") << endl;
	cout << (b.X >= (b.X + b.Y + 1) / 2 ? "LIVE" : "DEAD") << endl;
	return 0;
}
