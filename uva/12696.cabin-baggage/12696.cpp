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
const int MAXN = 2e5 + 123;
const double S_LIM = 125.00;

int main()
{
	int allowed = 0;
	int T;
	cin >> T;
	for(int test=0; test < T; test++)
	{
		double l, w, d, weight;
		cin >> l >> w >> d >> weight;
		double sum = l + w + d;
		bool valid = true;
		if(weight > 7.00) valid = false;
		if(l > 56.00 && sum > S_LIM) valid = false;
		if(w > 45.00 && sum > S_LIM) valid = false;
		if(d > 25.00 && sum > S_LIM) valid = false;
		allowed += valid;
		cout << valid << endl;
	}
	cout << allowed << endl;

	return 0;
}
