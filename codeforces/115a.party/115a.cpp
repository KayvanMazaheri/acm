#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2e3 + 123;

vector <int> list[MAXN];
vector <int> roots;
bool mark[MAXN];

int dfs(int x)
{
	if (mark[x])
		return 0;
	mark[x] = true;
	int mx_len = 0;
	for(int i=0; i<list[x].size(); i++)
		mx_len = max(mx_len, dfs(list[x][i]));
	return mx_len + 1;

}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		if (inp == -1)
		{
			roots.push_back(i);
			continue;
		}
		inp --;
		list[inp].push_back(i);
	}
	int result = -1;
	for(int i=0; i<roots.size(); i++)
		result = max(result, dfs(roots[i]));
	cout << result << endl;
	return 0;
}
