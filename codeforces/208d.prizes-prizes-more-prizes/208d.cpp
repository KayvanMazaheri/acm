#include <iostream>
using namespace std;

long long res[5];
int cost[5];
int inp[50 + 12];

int main()
{
	int n;
	long long point = 0;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> inp[i];
	for(int i=0; i<5; i++)
		cin >> cost[i];
	for(int i=0; i<n; i++)
	{
		point += inp[i];
		for(int j=4; j>=0; j--)
		{
			res[j] += point / cost[j];
			point %= cost[j];
		}
	}
	for(int i=0; i<5; i++)
		cout << res[i] << " ";
	cout << endl << point << endl;
	return 0;
}
