#include <iostream>

using namespace std;

char map[101][101];
bool mark[100];

int main()
{
    int n, m;
    char c;
    int result = 0;
    cin >> n >> m >> c;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if (map[i][j] == c)
            {
                if(i && map[i-1][j] != '.'  && map[i-1][j] != c  && !mark[map[i-1][j] - 'A'])
                {
                    mark[map[i-1][j] - 'A'] = true;
                    result ++;
                }
                if(j && map[i][j-1] != '.' && map[i][j-1] != c && !mark[map[i][j-1] - 'A'])
                {
                    mark[map[i][j-1] - 'A'] = true;
                    result ++;
                }
                if(i < n-1 && map[i+1][j] != '.' && map[i+1][j] != c && !mark[map[i+1][j] - 'A'])
                {
                    mark[map[i+1][j] - 'A'] = true;
                    result ++;
                }
                if(j < m-1 && map[i][j+1] != '.' && map[i][j+1] != c && !mark[map[i][j+1] - 'A'])
                {
                    mark[map[i][j+1] - 'A'] = true;
                    result ++;
                }
            }
	cout << result << endl;
	return 0;
}
