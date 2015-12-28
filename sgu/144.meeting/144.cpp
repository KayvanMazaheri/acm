#include <iostream>
#include <iomanip>
using namespace std;

#define FX(x) fixed << setprecision((x))

int main()
{
	double x;
	int a, b;
	cin >> a >> b >> x;
	double f = b - a ;
	double buff = (f * 60);
	cout << FX(7) << 1 - ( ((buff - x ) * (buff - x)) / (buff * buff ) )<< endl;
	return 0;
}
