#include <iostream>
using namespace std;

const int MAXN = 1e2 + 123;

int map[MAXN][MAXN];
int n, m, area = 0;

void tb();
void up();
void down();
void right();
void left();
void input();

int main()
{

    cin >> n >> m;
    input();
    tb();
    up();
    down();
    right();
    left();
    cout << area << endl;
    return 0;

}

void input()
{
    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
        {
        	char a;
        	cin >> a;
        	map[x][y] = a - '0';
        }

    return;
}
void tb()
{
    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
            if (map[x][y])
                area+=2;
}

void right()
{
    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
            if (map[x][y] > map[x+1][y])
                area += map[x][y] - map[x+1][y];
}

void left()
{
    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
            if (map[x][y] > map[x-1][y])
                area += map[x][y] - map[x-1][y];
}

void up()
{

    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
            if (map[x][y] > map[x][y+1])
                area += map[x][y] - map[x][y+1];
}
void down()
{

    for(int y = 1; y <=n; y++)
        for(int x = 1; x<=m; x++)
            if (map[x][y] > map[x][y-1])
                area += map[x][y] - map[x][y-1];
}
