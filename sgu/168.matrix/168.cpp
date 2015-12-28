#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 1e3 + 123;
const int INF = 32e3 + 1234;

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int m, n;

int g_min(int i, int j)
{
    int result = INF;
    result = a[i][j];
    result = min(result, b[i+1][j]);
    result = min(result, b[i-1][j+1]);
    result = min(result, b[i+1][j+1]);
    result = min(result, b[i][j+1]);
    return result;
}

int main()
{
	//ios::sync_with_stdio(false);
    for(int i=0; i<MAXN; i++)
        for(int j=0; j<MAXN; j++)
        {
            a[i][j] = INF;
            b[i][j] = INF;
        }

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &a[i][j]);

    for(int j=m; j; j--)
        for(int i=n; i; i--)
            b[i][j] = g_min(i, j);

    for (int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            printf ("%d ",  b[i][j]);
        cout << endl;
    }
    return 0;

}
