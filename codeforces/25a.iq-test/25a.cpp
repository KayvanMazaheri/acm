#include <iostream>
using namespace std;

const int MAXN = 1e3;

int arr[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	int different;
	for(int i=0; i<n-1; i++)
		if (arr[i] % 2 != arr[i+1] % 2)
		{
			different = i;
			break;
		}
	different+=2;
	if (different == 2 && (arr[0] % 2 != arr[n-1] % 2))
		different --;
	cout << different << endl;
	return 0;
}
