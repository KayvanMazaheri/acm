#include <iostream>
using namespace std;

const int MAXN = 4e3 + 123;

bool mark[MAXN][MAXN];
int result = -1;
int cuts[3];

void dfs(int pieces, int remain)
{
	if (mark[pieces][remain])
		return;
	mark[pieces][remain] = true;
	for (int i=0; i<3; i++)
		if (remain >= cuts[i])
			dfs(pieces + 1, remain - cuts[i]);
	if (!remain)
		result = max(result, pieces);
	return ;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<3; i++)
		cin >> cuts[i] ;
	dfs(0, n);
	cout << result << endl;
	return 0;
}
