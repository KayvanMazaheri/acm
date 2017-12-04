#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_INP = 5e3 + 123;

int num[MAX_INP];

vector <int> result;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		num[inp] ++;
	}
	for(int i=0; i<MAX_INP; i++)
	{
		int res = 0;
		for(int j=0; j<MAX_INP; j++)
			if (j < i || 2 * i < j)
				res += num[j];
//		cerr << i << " " << res << endl;
		result.push_back(res);
	}
	sort(result.begin(), result.end());
	cout << result[0] << endl;
	return 0;

}
