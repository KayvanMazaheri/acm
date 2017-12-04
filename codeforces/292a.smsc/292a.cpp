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

long long time = 0;
long long amount = 0;

long long mx_sz = -1;


int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		long long t, c;
		cin >> t >> c;
		t++;
		if (time > 0) amount -= min(amount,t - time);
		amount += c;
		time = t;
		mx_sz = max(mx_sz, amount);
	}
	cout << time + amount - 1 << " " << mx_sz << endl;

	return 0;
}
