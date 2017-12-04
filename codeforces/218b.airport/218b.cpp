#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e3 + 123;
int arr[MAXN];

int main()
{
	int min_cost = 0, max_cost = 0;
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
		cin >> arr[i];
	sort(arr, arr+m);
	for(int buff = n, i=0; buff; i++)
	{
		min_cost += (arr[i] * (arr[i] + 1)) / 2;
		if (buff < arr[i]) min_cost -= ((arr[i] - buff) * (arr[i] - buff + 1)) / 2;
		buff -= min(buff, arr[i]);
	}
	reverse(arr, arr+m);
	while(n)
	{
		int f =  arr[0];
		for(int i=0; i<m && arr[i] == f && n; i++)
		{
			n --;
			max_cost += arr[i];
			arr[i] --;
		}
	}
	cout << max_cost << " " << min_cost << endl;
	return 0;
}
