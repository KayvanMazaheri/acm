#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 60;

vector <int> friends[MAXN];
vector <int> fof;
bool mark[MAXN];

int main()
{
	int n, x;
	cin >> n >> x;
	x -- ;
	for(int i=0; i<n; i++)
	{
		int k;
		cin >> k;
		for(int j=0; j<k; j++)
		{
			int inp;
			cin >> inp;
			friends[i].push_back(inp-1);
		}
	}
	for(int i=0; i<friends[x].size(); i++)
		mark[friends[x][i]] = true;
	mark[x] = true;
	for(int i=0; i<friends[x].size(); i++)
	{
		int a = friends[x][i];
		for(int j=0; j<friends[a].size(); j++)
		{
			if (!mark[friends[a][j]])
			{
				mark[friends[a][j]] = true;
				fof.push_back(friends[a][j]);
			}
		}
	}
	sort(fof.begin(), fof.end());
	cout << fof.size() << endl;
	for(int i=0; i<fof.size(); i++)
		cout << fof[i] + 1 << " ";
	cout << endl;
	return 0;

}
