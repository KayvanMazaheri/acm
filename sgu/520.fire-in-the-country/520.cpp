#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e3 + 123;
queue <pair<int, int> > bfs_queue;
bool mark[MAXN];
vector <int> list[MAXN];
int h[MAXN];
vector <int> fire_g[MAXN];
string ans[2] = {"Nikolay", "Vladimir"};
int n, m;

bool dfs(int v, int h)
{
    if (fire_g[v].size() == 0)
        return false;
    bool result = false;
    for(int i=0; i<fire_g[v].size(); i++)
        if (dfs(fire_g[v][i], h++) == 0)
            result = true;
    return result;
}

void make_fire_g()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<list[i].size(); j++)
            if (h[i]+1 == h[list[i][j]])
                fire_g[i].push_back(list[i][j]);
    return;
}

void bfs()
{
    while(!bfs_queue.empty())
    {
        pair <int, int> v = bfs_queue.front();
        if (mark[v.X])
        {
            bfs_queue.pop();
            continue;
        }
        mark[v.X] = true;
        h[v.X] = v.Y;
        for(int i=0; i<list[v.X].size(); i++)
            if (!mark[list[v.X][i]])
            {
                bfs_queue.push(make_pair(list[v.X][i], v.Y+1));
                //fire_g[v.X].push_back(list[v.X][i]);
            }
        bfs_queue.pop();
    }
    return;
}

void input()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    return;
}

int main()
{
    input();
    bfs_queue.push(make_pair(0, 0));
    bfs();
    make_fire_g();
//    for(int i=0; i<n; i++)
//        cout << h[i] << " ";
//    cout << endl;
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<fire_g[i].size(); j++)
//            cout << fire_g[i][j] << " ";
//        cout << endl;
//    }
    cout << ans[dfs(0,0)] << endl;
    return 0;
}
