// K1
// :)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#define MAXN (int(1e9))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	long long a, b, br = 0;
	cin >> a >> b;
	while (b)
	{
		(br *= 10) += b % 10;
		b /= 10;
	}
	cout << a + br << endl;
	return 0;
}
