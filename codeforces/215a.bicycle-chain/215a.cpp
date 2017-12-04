#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a, b;
vector <int> result;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		a.push_back(inp);
	}
	int m;
	cin >> m;
	for(int i=0; i<m; i++)
	{
		int inp;
		cin >> inp;
		b.push_back(inp);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (b[j] % a[i] == 0)
				result.push_back(b[j] / a[i]);
	sort(result.begin(), result.end());
	reverse(result.begin(), result.end());
	int num = 0 ;
	for(num = 1; num < result.size() && result[num] == result[num-1] ; num++);
	cout << num << endl;
	return 0;
}
