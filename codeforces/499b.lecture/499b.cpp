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

map <string, string> mp;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	for (int i = 0; i < n; ++i)
	{
		string inp;
		cin >> inp;
		cout << (mp[inp].size() < inp.size() ? mp[inp] : inp) << " ";
	}
	cout << endl;

	return 0;
}