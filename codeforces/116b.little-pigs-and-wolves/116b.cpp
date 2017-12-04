#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1e1 + 12 ;

bool mark[MAXN][MAXN];
char map[MAXN][MAXN];
int eaten = 0;

bool find(int i, int j)
{
	if (i && map[i-1][j] =='P' && ! mark[i-1][j])
		return mark[i-1][j] = true ;
	else if (j && map[i][j-1] == 'P' && ! mark[i][j-1])
		return mark[i][j-1] = true ;
	else if (map[i+1][j] == 'P' && ! mark[i+1][j] )
		return mark[i+1][j] = true ;
	else if (map[i][j+1]=='P' && ! mark[i][j+1])
		return mark[i][j+1] = true ;
	return false ;
}

int main()
{
	int m, n;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> map[j][i];

	for (int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if (map[j][i] == 'W')
				if (find(j, i))
					eaten++;
	cout << eaten << endl ;
	return 0;
}
