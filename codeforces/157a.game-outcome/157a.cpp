#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 30;

int arr[MAXN][MAXN];
int col[MAXN];
int row[MAXN];

int main()
{
	int n, result = 0;
	cin >> n;
	for(int i=0; i<n ;i++)
	{
		//cerr << "a" << endl;
		for(int j=0; j<n; j++)
		{
			int a;
			//cerr  << "a" << endl;
			cin >> a;
			arr[j][i] = a;
			row[j] += arr[j][i];
		}
	}
	for(int j=0; j<n ;j++)
	{
		for(int i=0; i<n; i++)
		{
			col[i] += arr[j][i];
		}
	}
	for(int i=0; i<n ;i++)
		for(int j=0; j<n; j++)
			if (col[i] < row[j])
				result ++;
	cout << result << endl;
	return 0;
}
