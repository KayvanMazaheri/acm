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
	int tux;
	cin >> tux;
	int foo = 0;
	int bar = 0;
	int baz = 0;
	int quz = 0;
	for (; tux > 0; tux --)
	{
		int poor;
		cin >> poor;
		foo += poor;
		bar++;
		if (max(foo * quz , bar * baz) == foo * quz)
		{
			baz = foo;
			quz = bar;
		}
	}
	cout << FX(5) << double(baz) / quz << endl;

	return 0;
}
