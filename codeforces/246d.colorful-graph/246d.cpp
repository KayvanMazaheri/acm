#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 123;

set <int> q[MAX_N];
int color[MAX_N];

bool OP(const int a, const int &b)
{
	if (q[a].size() == q[b].size())
		return a > b;
	return q[a].size() < q[b].size();
}

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> color[i];
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (color[a] == color[b])
			continue;
		q[color[a]].insert(color[b]);
		q[color[b]].insert(color[a]);
	}
	int result = color[0];
	for(int i=0; i<n; i++)
		result = max(result, color[i], OP);
	cout << result << endl;
	return 0;

}
