#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e2 + 123;
int n, m;

vector <int> resources[MAXN];
bool mark[MAXN];

int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int t;
        cin >> t;
        for(int j=0; j<t; j++)
        {
            int res;
            cin >> res;
            res --;
            resources[res].push_back(i);
        }
    }
    for(int i=0; i<n; i++)
        sort(resources[i].begin(), resources[i].end());
    int result = n;
    for(int i=0; i<n; i++)
        if (resources[i].size() == 0)
        {
            mark[i] = true;
            result--;
        }
    for(int i=0; i<n; i++)
    {
        mark[i] = true;
        for(int j=0; j<n; j++)
        {
            if (!mark[j] && resources[i].size() == resources[j].size() )
            {
                bool same = true;
                for(int t = 0; t<resources[i].size(); t++)
                    if (resources[i][t] != resources[j][t])
                    {
                        same = false;
                        break;
                    }
                if (same == true)
                {
                    mark[j] = true;
                    result --;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}
