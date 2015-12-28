#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const int MAXN = 5e5 + 12;

bool mark[MAXN];
vector <int> list [MAXN];
vector <int> ans;
int dp[MAXN];

void dfs_out (int v, int func)
{
    mark[v] = true;
    if (func)
    {
        //cout << v+1 << " ";
        ans.push_back(v+1);
        for(int i=0; i<list[v].size(); i++)
        {
            if (!mark[list[v][i]])
                dfs_out(list[v][i], 0);
        }
    }
    else
    {
        for(int i=0; i<list[v].size(); i++)
        {
            if (!mark[list[v][i]])
                if (dp[v] == list[v][i])
                    dfs_out(list[v][i], 1);
                else
                    dfs_out(list[v][i], 0);
        }
    }
    return;
}

pair <int, int> dfs(int v)
{
    mark[v] = true;
    pair <int, int> result = make_pair(1, 0);

    pair <int, int> max_dif = make_pair (0,-1);

    for(int i=0; i<list[v].size(); i++)
    {
        pair <int, int> buff;
        if (!mark[list[v][i]])
        {
            buff = dfs(list[v][i]);

            result.X += buff.Y;
            result.Y += buff.Y;
            if (buff.X - buff.Y > 0 && buff.X - buff.Y > max_dif.X)
                max_dif = make_pair(buff.X - buff.Y, list[v][i]);
        }

    }
    if (max_dif.X > 0)
    {
        result.Y += max_dif.X;
        dp[v] = max_dif.Y;
    }
    //cerr << v+1 << " : " << result.X << ", " << result.Y << endl;
    return result;
}

void input()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int inp;
        cin >> inp;
        inp --;
        list[inp].push_back(i);
    }
    return;
}

int main()
{
    for(int i=0; i<MAXN; i++)
        dp[i] = -1;
    input();
    pair <int, int> result;
    result = dfs(0);
    for(int i=0; i<MAXN; i++)
        mark[i] = false;
//	if (result.X > result.Y)
//	{
//		cout << result.X * 1000 << endl;
//		dfs_out(0, 1);
//	}
//	else

// khode Bill hates nemitoone biad bara hamin .Y esho dar nazar migirim !

    {
        cout << result.Y * 1000 << endl;
        dfs_out(0, 0);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
