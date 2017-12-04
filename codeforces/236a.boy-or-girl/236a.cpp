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

#define MAXN (int(1e3))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

int mark[MAXN];

int main()
{
	string s;
	int count = 0;
	cin >> s;
	for(int i=0; i<s.size(); i++)
		if (!mark[s[i]])
		{
			mark[s[i]] = true;
			count ++;
		}
	cout << ((count%2)? "IGNORE HIM!" :"CHAT WITH HER!") << endl;
	return 0;
}
