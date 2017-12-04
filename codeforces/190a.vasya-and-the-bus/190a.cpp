#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	if (!n && m)
		cout << "Impossible" << endl;
	else
		cout << n + (m-n > 0 ? m - n : 0) << " " << m + n - bool(m) << endl;
	return 0;
}
