#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main()
{

	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	arr[0] = (k * l) / (n * nl);
	arr[1] = (c * d) / n;
	arr[2] = p / (n * np);
	cout << *min_element(arr, arr+3) << endl;
	return 0;
}
