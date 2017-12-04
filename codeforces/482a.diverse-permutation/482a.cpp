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

bool mark[MAXN];

int main()
{
	int k, n;
	cin >> n >> k;
	point pos = make_pair(1, k+1);
	for (int i = 0; i < k; ++i)
	{
		if(i % 2 == 0)
		{
			cout << pos.X << " ";
			mark[pos.X] = true;
			while(mark[++pos.X]);
		}
		else
		{

			cout << pos.Y << " ";
			mark[pos.Y] = true;
			while(mark[--pos.Y]);	
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if(!mark[i]) cout << i << " ";
	}
	cout << endl;

	cout << endl;
	return 0;
}