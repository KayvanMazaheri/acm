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

const int MAXN = 1e3;

int arr[MAXN];
long long p[3];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<n; i++)
		p[i%3] += arr[i];
	if (p[0] > p[1] && p[0] > p[2])
		cout << "chest" << endl;
	else if (p[1] > p[0] && p[1] > p[2])
		cout << "biceps" << endl;
	else
		cout << "back" << endl;
		return 0;

	return 0;
}
