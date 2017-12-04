#include <iostream>
#include <algorithm>
using namespace std;

bool tri(int a, int b, int c)
{
	if(a + b > c)
		if (b + c > a)
			if (a + c > b)
				return true;
	return false;
}

bool seg(int a, int b, int c)
{
	int arr[] = {a, b, c};
	sort(arr, arr+3);
		return arr[0] + arr[1] == arr[2];
}

int main()
{
	int arr[4];
	for(int i=0; i<4; i++)
		cin >> arr[i];
	sort(arr, arr+4);
	do
	{
		if (tri(arr[0], arr[1], arr[2]))
		{
			cout << "TRIANGLE" << endl;
			return 0;
		}

	}while(next_permutation(arr, arr+4));
	do
	{
		if (seg(arr[0], arr[1], arr[2]))
		{
			cout << "SEGMENT" << endl;
			return 0;
		}

	}while(next_permutation(arr, arr+4));

	cout << "IMPOSSIBLE" << endl;
	return 0;
}
