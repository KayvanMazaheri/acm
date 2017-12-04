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

vector <int> vec;

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(inp);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	if (k > n)
		cout << -1 << endl;
	else
		cout << vec[k-1] << " " << vec[k-1] << endl;

	return 0;
}
