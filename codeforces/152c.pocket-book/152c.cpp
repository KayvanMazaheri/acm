#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 333 ;
const int g = 1e9 + 7;

int arr[MAXN];
bool mark[MAXN][27];

long long fact(int n)
{
	if(n<=1)
		return 1;
	return n * fact(n-1);
}

int main()
{

	int n, m;
	cin >> n >> m;
	string inp;
	for(int i=0; i<n; i++)
	{
		cin >> inp;
		for(int j=0; j<m; j++)
		{
			if(!mark[j][inp[j]-'A'])
			{
				mark[j][inp[j]-'A'] = true ;
				arr[j] ++;
			}
		}

	}

	long long result = 1;
	for(int i=0; i<m; i++)
	{
		result *= arr[i];
		result = result % g;
	}
	cout << result << endl;
	return 0;
}
