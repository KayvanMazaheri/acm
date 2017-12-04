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
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 1e9;

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a;
	long long result = a;
	a = 0;
	while(!(a == 0 && c < b))
	{
		a += c / b;
		c %= b;
		result += a;
		c += a;
		a = 0;
	}
	cout << result << endl;

	return 0;
}
