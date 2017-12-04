#include <iostream>
using namespace std;

int main()
{
	int a, b, r;
	cin >> a >> b >> r;
	cout << (2 * r > min(a, b) ? "Second" : "First") << endl;
	return 0;
}
