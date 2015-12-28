#include <iostream>
#include <string>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e2 + 123;

char map[MAXN][MAXN];
pair <int, int> cd;

int main()
{
    int m, n;
	cin >> m >> n;
	for(int j=0; j<m; j++)
		for(int i=0; i<n; i++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'P' || map[i][j] == 'p')
				cd = make_pair(i, j);
		}
	char last = '.';
	while(1)
	{
		//cerr << cd.X << " " << cd.Y << endl;
		if (cd.X < 0 || cd.X >= n || (map[cd.X][cd.Y] == '/' && last == '\\') || (map[cd.X][cd.Y] == '\\' && last == '/') )
		{
			cout << -1 << endl;
			return 0;
		}
		if (cd.Y == m)
		{
			cout << cd.X + 1 << endl;
			return 0;
		}
		if (map[cd.X][cd.Y] == '/' && last != '/')
		{
			cd.X --;
			last = '/';
		}
		else if (map[cd.X][cd.Y] == '\\' && last != '\\')
		{
			cd.X ++;
			last = '\\';
		}
		else
		{
			cd.Y ++;
			last = '.';
		}

	}

}
