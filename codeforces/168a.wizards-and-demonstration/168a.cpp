// K1
// :)

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
	ios::sync_with_stdio(false);

	long long n, x, y;
	cin >> n >> x >> y;
//	n *= 1000;
//	x *= 1000;
	double need = ((y * n)) / 100;
	long long result = need - x;
	int ne = need;
//	result /= 1000;
//	double more = need - ne;
//	ne *= 100;
	if (result < 0)
		result = 0;
	int percent =  ((result + x) * 100 ) / n;
	if (percent < y)
		result ++;
	if (result < 0)
		result = 0;
	cout << result << endl;
	return 0;
}
