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
const int MAXN = 1e9;

int main()
{
	int n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	for(int i=0; i<t; i++)
	{
		for(int j=0; j < n-1; j++)
			if (s[j] == 'B' && s[j+1] == 'G')
			{
				swap(s[j], s[j+1]);
				j++;
			}
	}
	cout << s << endl;

	return 0;
}
