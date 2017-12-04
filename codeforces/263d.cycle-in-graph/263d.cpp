// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

const int MAXN = 1e5 + 123;

bool mark[MAXN];
int par[MAXN];
int len[MAXN];
vector <int> list[MAXN];
int result = -1;
int k;

void dfs(int v, int parent, int h)
{
//	cerr << "DFS ON " << v << " PAR : " << parent << " H: " << h <<  endl;
    mark[v] = true;
    par[v] = parent;
    len[v] = h;
    for(int i=0; i<list[v].size(); i++)
    {
        if (mark[list[v][i]] && result == -1)
        {
//        	cerr << "CHECKING " << list[v][i] << " " << len[list[v][i]] << "  " << v <<  endl;
            if (abs(h - len[list[v][i]]) >= k )
            {
            	par[list[v][i]] = -1;
                result = v;
                return;
            }
        }
        else if (!mark[list[v][i]])
            dfs(list[v][i], v, h+1);
    }
    return;
}

vector <int> res_vec;

int main()
{
    int n, m;
    cin >> n >> m >> k;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    for(int i=0; i<n; i++)
    {
    	//cerr << "#" << endl;
        if (result == -1 && !mark[i])
            dfs(i, -1, 0);
    }

//    cerr << result << endl;

    //cerr << "END" << endl;
    while(result != -1)
    {
    	//cerr << result << endl;
        res_vec.push_back(result);
        result = par[result];
    }


    cout << res_vec.size() << endl;
    for(int i=0; i<res_vec.size(); i++)
        cout << res_vec[i] + 1 << " ";
    cout << endl;

    return 0;
}
