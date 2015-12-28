#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 3e4 + 123;

vector <int> vec[MAXN];
bool color[MAXN];
bool mark[MAXN];

bool dfs(int v, bool c)
{
    // v -- > Vertex index
    // c --> color of vertex V
    // result = 1  -- > vaghT ke dore fard nadashte bashim ! :D
    color[v] = c;
    mark[v] = true;
    int result = 1;
    for(int i = 0; i< vec[v].size(); i++)
    {
        if(!mark[vec[v][i]])
            result *= dfs(vec[v][i], !c);
        else if (color[vec[v][i]] == c)
            return false;
    }
    return result;
}


int main()
{
    int n, m;
    cin >> m >> n;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int result = 1;
    for(int i=1; i<m; i++)
    {
        if (!mark[i])
            result *= dfs(i, 1);
    }
    if(!result)
        cout << "no" << endl;
    else
    {
        cout << "yes" << endl;
        int result = 0;
        for(int i=0; i<=MAXN; i++)
            if(color[i])
                result ++;
        cout << result << endl;
        for(int i=0; i<=MAXN; i++)
            if(color[i])
                cout << i << " ";
        cout << endl;
    }
    return 0;

}
