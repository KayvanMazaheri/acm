#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	long long result = 0;
	long long product = a * b * c;
	product = sqrt(product);
	result =  product / a + product / b + product / c;
	cout << result * 4 << endl;
	return 0;
}
