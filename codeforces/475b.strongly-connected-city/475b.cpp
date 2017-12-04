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
	int n, m;
	cin >> n >> m;
	string h, v;
	cin >> h >> v;
	if((h[0] == '>' && h[n-1] == '<' && v[0] == '^' && v[m-1] == 'v') || (h[0] == '<' && h[n-1] == '>' && v[0] == 'v' && v[m-1] == '^'))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}