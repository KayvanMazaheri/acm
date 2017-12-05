#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


typedef pair<long long, long long> point;
#define X first
#define Y second

int main() {
	int n;
	cin >> n;

	map<long long, long long> x_axis;
	map<long long, long long> y_axis;
	map<point, long long> both;

	for (int i = 0; i < n; ++i)
	{
		point p;
		cin >> p.X >> p.Y;

		x_axis[p.X] ++;
		y_axis[p.Y] ++;
		both[p] ++;
	}

	long long result = 0;

	for (auto it = x_axis.begin(); it != x_axis.end(); ++it) {
		long long count = it->second;
		result += (count * (count - 1)) / 2;
	}

	for (auto it = y_axis.begin(); it != y_axis.end(); ++it) {
		long long count = it->second;
		result += (count * (count - 1)) / 2;
	}

	for (auto it = both.begin(); it != both.end(); ++it) {
		long long count = it->second;
		result -= (count * (count - 1)) / 2;
	}

	cout << result << endl;
	return 0;
}
