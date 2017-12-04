#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define eps 1E-8
#define sqr(x) ((x) * (x))
#define prec(x) fixed << setprecision (x)
#define dis(x1,y1,x2,y2) (sqrt (abs((sqr ((x1) - (x2)))+(sqr ((y1) - (y2))))))
#define point pair <int, int>
#define X first
#define Y second

using namespace std;

const int MAXN = 1e2 + 123;
point sign[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		int x, y;
		cin >> x >> y;
		sign[i] = make_pair(x, y);
	}
	double allDis = 0;
	for(int i=0; i<n-1; i++)
		allDis += dis(sign[i].X, sign[i].Y, sign[i+1].X, sign[i+1].Y);
	allDis /= 50;
	allDis *= k;
	cout << prec(9) << allDis << endl;
	return 0;
}
