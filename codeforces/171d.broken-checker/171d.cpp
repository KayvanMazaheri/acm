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
	int a;
	cin >> a;
	if (a == 5)
		cout << 1 << endl;
	else
		cout << a%3 + 1 << endl;
	return 0;
}
