#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, face;
	cin >> n >> face;
	bool flag = true;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == face || b == face || fabs(7-a) == face || fabs(7-b) == face)
			flag = false;
	}
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}
