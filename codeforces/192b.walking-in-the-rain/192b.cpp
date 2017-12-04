#include <iostream>
using namespace std;

const int MAX_N = 1e3 + 123;

int arr[MAX_N];

bool check(int x, int n)
{
	if (arr[0] - x < 0)
		return false;
	int i;
	for(i=0; i<n; )
	{
		if(arr[i+1] - x >= 0)
			i++;
		else if (arr[i+2] - x >= 0)
			i+=2;
		else
			break;
	}
	return (i == n-1);
}

int binary_search(int head, int tail, int n)
{
//	cerr << head << " " << tail << endl;
	int mid = (head + tail) / 2;
	if (tail - head < 5)
	{
		for(int i=tail; i>=head; i--)
			if (check(i, n))
				return i;
	}
	if (check(mid, n))
		return binary_search(mid, tail, n);
	return binary_search(head, mid, n);
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	cout << binary_search(0, MAX_N, n);
	return 0;
}
