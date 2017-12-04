// K1
// :)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>

#define MAXN (int(100))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

int arr[MAXN][MAXN];

int main()
{
	int result = 1;
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] ++;
		if (arr[a][b] > result)
			result = arr[a][b];
	}
	cout << result << endl;
	return 0;
}
