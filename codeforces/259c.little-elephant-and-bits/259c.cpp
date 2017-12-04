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
	string s;
	cin >> s;
	int pos = s.find('0');
	if (pos == string::npos)
		cout << s.substr(1) << endl;
	else
		cout << s.substr(0, pos) + s.substr(pos+1) << endl;
	return 0;

	return 0;
}
