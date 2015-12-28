#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200 + 123;
vector <int> ans;
int n, k;
int matrix[MAXN][MAXN];
int route[MAXN];
bool mark[MAXN][MAXN];

void dfs(int v, int h)
{
	mark[v][h] = true;
	if (h == k)
	{
		ans.push_back(v);
		return;
	}
	for(int i=0; i<n; i++)
		if (matrix[v][i] == route[h] && !mark[i][h+1])
			dfs(i, h+1);
	return;
}

int main()
{
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> matrix[i][j];
	cin >> k;
	for(int i=0; i<k; i++)
		cin >> route[i];
	dfs(0, 0);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++)
		cout << ans[i]+1 << " ";
	cout << endl;
	return 0;
}
