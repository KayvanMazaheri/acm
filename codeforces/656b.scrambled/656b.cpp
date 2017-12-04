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

const long long up = 30330;

bool mark[up + 1];
int m[100];
int r[100];

int main()
{
	int n;
	int total = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> m[i];
	for (int i = 0; i < n; ++i)
		cin >> r[i];
	for (int i = 0; i < up; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(i % m[j] == r[j])
				mark[i] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < up; ++i)
	{
		if(mark[i])
			count++;
	}

	cout << FX(4) << (double) count / up << endl;
	return 0;
}