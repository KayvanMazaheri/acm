#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

const int MAXN = 2e4;
const int sc = 1e7;
int n;
pair <int, int> city[MAXN];

double f(double x)
{
	double result = 0;
	for(int i=0; i<n; i++)
		result += (double(city[i].Y) * abs(double(city[i].X) - x));
	return result;
}

int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> city[i].X >> city[i].Y;
	int scale = 1e9;
	double result = 10;
	while(scale)
	{
		double k = double(scale)/double(sc);
		//cerr << k << " " << result << endl;
		double now_f = f(result);
		if (now_f >= f(result + k))
			result += k;
		else if (now_f > f(result - k))
			result -= k;
		else
			scale /= 10;
	}
	cout << FX(5) << result << endl;
}
