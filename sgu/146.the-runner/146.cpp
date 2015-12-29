#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define fx(a, x)  fixed << setprecision(a) << x
#define eps 1e-8

using namespace std;

int main()
{
	long double l;
	long long dis = 0 ;
	long long n, v, d;
	cin >> l >> n;
	long long L = l * 1e4;
	for(int i=0; i<n; i++)
	{
		cin >> v >> d;
		dis += v * d * 1e4;
		dis %= L;
	}

	if (L - dis < dis)
		dis = L - dis;
	double result = double(((double)dis + eps) / (long double)1e4) + eps;
	cout << fx(4, result) << endl;
	return 0;
}
