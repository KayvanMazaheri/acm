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

int arr[120];
int neg[120];

int main()
{
	int n, f = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		if (inp < 0 && neg[f] == 2)
			f++;
		arr[f] ++;
		if (inp < 0)
			neg[f] ++;
	}
	cout << f+1 << endl;
	for(int i=0; i<=f; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}
