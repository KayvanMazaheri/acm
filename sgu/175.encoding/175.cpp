#include <iostream>
using namespace std;

int f(int n, int l)
{
    //cerr <<  n << " " << l << endl;
	int sar = l - l/2;
	if (l == 1)
		return 1;
	if (n <= l/2)
		return f(l/2 - n + 1, l/2) + sar;
	else
		return f(sar-((n-l/2))+1, sar);
}

int main()
{
	int n, q;
	cin >> n >> q;
	cout << f(q, n) << endl;
	return 0;
}
