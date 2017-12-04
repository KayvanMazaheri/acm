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
	int n, x;
	cin >> n >> x;
	long long result = 0;
	int pos = 1;
	for (int i = 0; i < n; ++i)
	{
		point inp;
		cin >> inp.X >> inp.Y;
		result += inp.Y - inp.X + 1 ;
		result += ( inp.X - pos ) % x;
		pos = inp.Y + 1;
	}
	cout << result << endl;


	return 0;
}