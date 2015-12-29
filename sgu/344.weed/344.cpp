#include <iostream>
#include <vector>
#include <algorithm>

#define point pair <int, int>
#define X first
#define Y second

using namespace std;

const int MAXN = 1e3 + 123;

int map[MAXN][MAXN];
bool mark[MAXN][MAXN];
vector < point > queue;
int n, m;

void check(point a);
void update(point a);

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
        {
            char inp;
            cin >> inp;
            if (inp == 'X')
            {
                queue.push_back(make_pair(j, i));
                //update(make_pair(j, i));
                mark[j][i] = true;
            }
        }

    for (int P=0; P<queue.size(); P++)
    {
        update(queue[P]);
        check(make_pair(queue[P].X - 1, queue[P].Y));
        check(make_pair(queue[P].X + 1, queue[P].Y));
        check(make_pair(queue[P].X, queue[P].Y - 1));
        check(make_pair(queue[P].X, queue[P].Y + 1));
    }
    cout << queue.size() << endl;
    return 0;
}

void check(point a)
{
    if (a.X >= m || a.X < 0)
        return ;
    if (a.Y >= n || a.Y < 0)
        return ;
    if (mark[a.X][a.Y])
        return ;
    if (map[a.X][a.Y] > 1)
    {
        mark[a.X][a.Y] = true;
        queue.push_back(a);
    }
    return;
}

void update(point a)
{
    point buff = make_pair(a.X - 1, a.Y);
    if (!(buff.X >= m || buff.X < 0 || buff.Y >= n || buff.Y < 0 || mark[buff.X][buff.Y]))
        map[buff.X][buff.Y] ++;
    buff = make_pair(a.X + 1, a.Y);
    if (!(buff.X >= m || buff.X < 0 || buff.Y >= n || buff.Y < 0 || mark[buff.X][buff.Y]))
        map[buff.X][buff.Y] ++;
    buff = make_pair(a.X, a.Y - 1);
    if (!(buff.X >= m || buff.X < 0 || buff.Y >= n || buff.Y < 0 || mark[buff.X][buff.Y]))
        map[buff.X][buff.Y] ++;
    buff = make_pair(a.X, a.Y + 1);
    if (!(buff.X >= m || buff.X < 0 || buff.Y >= n || buff.Y < 0 || mark[buff.X][buff.Y]))
        map[buff.X][buff.Y] ++;
    return ;
}
