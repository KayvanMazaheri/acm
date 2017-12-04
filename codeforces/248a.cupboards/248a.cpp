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
	int n;
	cin >> n;
	int left_open = 0, left_close = 0;
	int right_open = 0, right_close = 0;
	for(int i=0; i<n; i++)
	{
		int left, right;
		cin >> left >> right;
		(left ? left_open : left_close) ++;
		(right ? right_open : right_close) ++;
	}
	int result = 0;
	result += min(left_open , left_close);
	result += min(right_open , right_close);
	cout << result << endl;
	return 0;
}
