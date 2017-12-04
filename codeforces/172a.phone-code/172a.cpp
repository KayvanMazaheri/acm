#include <iostream>
#include <string>
using namespace std;

const int MAX_N = 3e4 + 123;

string number[MAX_N];

int solve(int n, int sz)
{
	int result ;
	for(result = 0; result < sz; result++)
		for(int i=0; i<n; i++)
			if (number[i][result] != number[0][result])
				return result;
	return -1;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> number[i];
	int sz = number[0].size();
	cout << solve(n, sz) << endl;
	return 0;
}
