#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int MAXN = 200;


vector<int> graph[MAXN];
int low[MAXN];
int par[MAXN];
int dfsn[MAXN];
bool mark[MAXN];
bool ap[MAXN];

int apcnt = 0;
int dfsc = 0;
int res = 0;


void dfs(int v) {
	// cerr << "in dfs " << v << endl;
	mark[v] = true;
	int childs = 0;

	dfsn[v] = low[v] = ++dfsc;

	for (int i = 0; i < graph[v].size(); ++i)
	{
		int u = graph[v][i];

		if (!mark[u]) {
			childs++;
			par[u] = v;
			dfs(u);
			low[v] = min(low[v], low[u]);
			if (par[v] == v && childs > 1 && !ap[v]) {
				res++;
				ap[v] = true;
			}
			if (par[v] != v && dfsn[v] <= low[u] && !ap[v]) {
				res++;
				ap[v] = true;
				// cerr << "detected ap in dfs " << v << " , ap is " << v << endl;
			}
		} else if (u != par[v]) {
			low[v] = min(low[v], dfsn[u]);
		}
	}
	// cerr << "dfs " << v << " ended with low = " << low[v] << " and dfsn = " << dfsn[v] << " and childs = " << childs << " and par = " << par[v] << endl;
	return;
}

int main() {
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < MAXN; ++i)
		{
			graph[i].clear();
			mark[i] = false;
			ap[i] = false;
			par[i] = i;
			low[i] = 0;
			dfsn[i] = 0;
			apcnt = 0;
			dfsc = 0;
			res = 0;
		}

		int v;
		string inp;
		while(cin >> v && v) {
			getline(cin, inp);
			istringstream sin(inp);
			int u;
			while(sin >> u){
				graph[v-1].push_back(u-1);
				graph[u-1].push_back(v-1);
			}
		}
		for (int i = 0; i < n; ++i)
		{
			if (!mark[i]){
				// cerr << "running dfs on " << i << endl;
				dfs(i);
			}
		}

		cout << res << endl;

	}
}