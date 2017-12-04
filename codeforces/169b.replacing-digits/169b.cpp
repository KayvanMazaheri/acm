#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#define MAXN (int(1e9))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;


int main()
{
	string a, s;
	cin >> a >> s;
	sort(s.begin(), s.end());
	int pointer = s.size() - 1;
	for (int i=0; i<a.size() && pointer >= 0; i++)
		if (a[i] < s[pointer])
			a[i] = s[pointer--];
	cout << a << endl;
	return 0;
}
