#include <iostream>
using namespace std;

const int MAX_N = 1e5 + 123;

int inp[MAX_N];
int _left[MAX_N];
int _right[MAX_N];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> inp[i];
	_left[0] = inp[0];
	_right[n-1] = inp[n-1];
	for(int i=1; i<n; i++)
		_left[i] = _left[i-1] + inp[i];
	for(int i=n-2; i >=0; i--)
		_right[i] = _right[i+1] + inp[i];
	int num;
	for(num = 1 ; num < n-1 && _left[num] <= _right[num] ; num++);
	cout << num  << " " << n-num << endl;
	return 0;
}
