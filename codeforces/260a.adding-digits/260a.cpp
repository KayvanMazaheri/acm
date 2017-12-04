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
	int a, b, n;
	cin >> a >> b >> n;
	bool flag = false;
	for(int i=0; i<10; i++)
	{
		int buff = (a * 10) + i;
		if (buff % b == 0)
		{
			flag = true;
			a = buff;
			break;
		}
	}
	if (!flag)
		cout << -1 << endl;
	else
	{
		cout << a ;
		for(int i=0; i<n-1; i++)
			cout << 0;
		cout << endl;
	}
	return 0;
	return 0;
}
