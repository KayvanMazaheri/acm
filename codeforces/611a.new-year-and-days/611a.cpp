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

int week[] = {52, 52, 52, 52, 53, 53, 52};
int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30,31, 30, 31};

int main()
{
	string s, of;
	int n;
	cin >> n >> of >> s;
	if(s == "week")
		cout << week[n-1] << endl;
	else
	{
		int result = 0;
		for (int i = 0; i < 12; ++i)
		{
			if(month[i] >= n)
				result ++;
		}
		cout << result << endl;
	}

	return 0;
}