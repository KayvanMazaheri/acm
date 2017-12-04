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


int main()
{
	vector<long long> all_one;
	vector<long long> vec;
	for (long long i = 4; i > 0 && i < 2e18 + 123; i*=2)
	{
		all_one.push_back(i-1);
	}
	all_one.push_back((*(all_one.rbegin() ) - 1) * 2 + 1);

	for (long long i = 1; i > 0 && i < 2e18 + 123; i*=2)
	{
		for (int j = 0; j < all_one.size(); ++j)
		{
			if(i < all_one[j] && i < ((all_one[j] + 1) / 2))
				vec.push_back(all_one[j] - i);
		}
	}

	sort(vec.begin(), vec.end());
	// cerr << vec[0] << " " << vec[1] << " " << vec[2] << endl;
	long long a, b;
	cin >> a >> b;
	int apos, bpos;
	bpos = upper_bound(vec.begin(), vec.end(), b) - vec.begin();
	apos = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
	cout << bpos - apos << endl;
	return 0;
}