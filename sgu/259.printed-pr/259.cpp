#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e3;

int print[MAXN];
int car[MAXN];

pair <int, int> order[MAXN];

void reverce(int n)
{
	for(int i=0; i<n/2; i++)
		swap(order[i], order[n-i-1]);
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> print[i] ;
	for(int i=0; i<n; i++)
		cin >> car[i];
	for(int i=0; i<n; i++)
		order[i] = make_pair(car[i], print[i]);
	sort(order, order + n);
	reverce(n);
	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++)
			order[j].X -= order[i].Y;
	long long result = 0, maximum = 0;
	for(int i=0; i<n; i++)
	{
		result += order[i].Y;
		if (order[i].X > maximum)
			maximum = order[i].X;
	}
	if (maximum)
		result += maximum;
	cout << result << endl;
	return 0;
}
