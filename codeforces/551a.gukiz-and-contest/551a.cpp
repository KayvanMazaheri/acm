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

vector <int> inp;
int arr[MAXN];

int sum[MAXN];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int buff;
		cin >> buff;
		inp.push_back(buff);
		arr[buff] ++;
	}
	sum[0] = arr[0];
	for (int i = 1; i < MAXN; ++i)
	{
		sum[i] = sum[i-1] + arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cout << n - sum[inp[i]] + 1 << " ";
	}
	cout << endl;

	return 0;
}