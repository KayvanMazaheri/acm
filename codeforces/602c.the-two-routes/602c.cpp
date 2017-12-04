// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define EPS 1e-8
#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 2e5 + 123;

vector<int> vec[500];
bool adj[500][500];

bool mark[500];
int lvl[500];

int main()
{
	fill(lvl, lvl+500, -1);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		a--;
		b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
		adj[a][b] = adj[b][a] = 1;
	}
	if(adj[0][n-1])
	{
		for (int i = 0; i < n; ++i)
		{
			vec[i].clear();
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(!adj[i][j])
					vec[i].push_back(j);
			}
		}
	}

	vector <int> q;
	q.push_back(0);
	lvl[0] = 0;
	for (int i = 0; i < q.size(); ++i)
	{
		int v = q[i];
		mark[v] = true;
		for (int j = 0; j < vec[v].size(); ++j)
		{
			if(!mark[vec[v][j]])
			{
				mark[vec[v][j]] = true;
				lvl[vec[v][j]]  = lvl[v] + 1;
				q.push_back(vec[v][j]);
			}
		}
	}
	if(lvl[n-1] == -1){
		cout << -1 << endl;
	}
	else
	{
		cout << lvl[n-1] << endl;
	}



	return 0;
}