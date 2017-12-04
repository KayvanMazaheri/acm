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

const int MAXN = 1e2;

int arr[MAXN];

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++)
		cin >> arr[i];
		sort(arr, arr+n);
		reverse(arr, arr+n);
	int av = k;
	int result = 0;
	int on = 0;
	while(av < m && on < n)
	{
		av --;
		av += arr[on];
		result ++;
		on ++;
	}
	if (on == n && av < m)
		cout << -1 << endl;
	else
		cout << result << endl;
	return 0;

}
