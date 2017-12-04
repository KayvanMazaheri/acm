#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 1e6;

int arr[MAXN];

int main()
{
	int n, k, t;
	cin >> n >> k >> t;
	for(int i=0; i < t * n / 100 ; i++)
		arr[i] = k;
	arr[t * n / 100] = ((t * n * k / 100) - (int(t * n / 100) * k)) ; //* (n * k / 100);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
