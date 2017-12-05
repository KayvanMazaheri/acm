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
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		string s;
		cin >> k >> s;
		cout << i+1 << " ";
		s = s.substr(0, k-1) + s.substr(k, s.size());
		cout << s << endl;
	}

	return 0;
}
