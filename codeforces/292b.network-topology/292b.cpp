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
const int MAXN = 1e5 + 123;

vector <int> list[MAXN];
bool mark[MAXN];

int comp = 0;

int deg1 = 0;
int deg2 = 0;
int delta = 0;

void dfs(int v)
{
	if (mark[v]) return;
	mark[v] = true;
	for(int i=0; i<list[v].size(); i++)
		dfs(list[v][i]);
	return;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		list[a].push_back(b);
		list[b].push_back(a);
	}
	for(int i=0; i<n; i++)
	{
		if (!mark[i])
		{
			dfs(i);
			comp++;
		}
	}
	for(int i=0; i<n; i++)
	{
		if (list[i].size() == 1) deg1++;
		else if (list[i].size() == 2) deg2++;
		else if (list[i].size() == n-1) delta++;
	}
	if (comp == 1 && deg1 == 2 && deg2 == n-2)
		cout << "bus topology" << endl;
	else if (comp == 1 && deg1 == 0 && deg2 == n)
		cout << "ring topology" << endl;
	else if (comp == 1 && deg1 == n-1 && delta == 1)
		cout << "star topology" << endl;
	else
		cout << "unknown topology" << endl;


	return 0;
}
