#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 5e4 + 123;

bool mark[MAX_N];
int par[MAX_N];
vector <int> list[MAX_N];

void dfs(int v, int dad)
{
	if (mark[v])
		return;
	mark[v] = true;
	par[v] = dad;
	for(int i=0; i<list[v].size(); i++)
		dfs(list[v][i], v);
	return ;
}

int main()
{
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	r1 --; r2 --;
	for(int i=0; i<n; i++)
	{
		if (i == r1)
			continue;
		int inp;
		cin >> inp;
		inp --;
		list[inp].push_back(i);
		list[i].push_back(inp);
	}
	dfs(r2, -1);
	for(int i=0; i<n; i++)
	{
		if (i == r2)
			continue;
		cout << par[i] + 1  << " ";
	}
	cout << endl;
	return 0;
}
