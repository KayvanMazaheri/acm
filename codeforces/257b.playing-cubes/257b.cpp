// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

const int MAXN = 1e9;

int main()
{
	int m, n;
	cin >> m >> n;
	int total = m + n - 1;
	if (m < n)
		swap(n, m);

	int _n = n, _m = m;

	int result = 0;
	result ++;
	n--;
	result += ((n + 1) / 2) * 2;
	while(n > 0)
	{
		n -= 2;
		if (n <= 0 && m <= 0)
			result--;
			m-= 2;
	}

	m = _m;
	n = _n;
	int _result = 0;
	m--;
	_result += ((n + 1) / 2) * 2;
	while(n > 0)
	{
		n -= 2;
		if (n <= 0 && m <= 0)
			_result--;
			m-= 2;
	}
	result = min(result, _result);
	cout << total - result << " " << result << endl;
	return 0;
}
