#include <iostream>
#include <iomanip>

#define FX(x) fixed << setprecision(x)

using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		sum += inp;
	}

	double result = double(sum) / n;
	cout << FX(5) << result << endl;
	return 0;
}
