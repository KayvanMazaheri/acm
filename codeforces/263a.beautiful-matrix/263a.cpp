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

int main()
{
	point pos;
	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			{
				int inp;
				cin >> inp;
				if (inp)
					pos = make_pair(i, j);
			}
	cout << abs(pos.X - 2) + abs(pos.Y-2) << endl;
	return 0;

	return 0;
}
