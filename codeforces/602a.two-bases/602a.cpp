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
const int MAXN = 2e5 + 123;


int main()
{
	int n, b1;
	cin >> n >> b1;
	long long x = 0;
	for (int i = 0; i < n; ++i)
	{
		long long inp ;
		cin >> inp;
		(x *= b1) += inp;
	}

	int m, b2;
	cin >> m >> b2;
	long long y = 0;
	for (int i = 0; i < m; ++i)
	{
		long long inp ;
		cin >> inp;
		(y *= b2) += inp;
	}

	if(x == y)
		cout << "=" << endl;
	else if(x < y)
		cout << "<" << endl;
	else
		cout << ">" << endl;
	return 0;
}