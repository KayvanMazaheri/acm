#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1e2 + 333 ;

string exam[MAXN];
bool mark[MAXN];

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; i++)
		cin >> exam[i];
	for(int i=0; i<m; i++)
	{
		pair <int, int> best[n];
		for(int j=0; j<n; j++)
		{
			best[j].first = exam[j][i];
			best[j].second = j;
		}
		sort(best, best+n);
		for (int j=n-1; j>=0 && best[j].first == best[n-1].first; j--)
			mark[best[j].second]=true;
	}

	int s = 0;

	for(int i = 0; i<n; i++)
		if(mark[i])
			s++;

	cout << s << endl ;
	return 0;

}

