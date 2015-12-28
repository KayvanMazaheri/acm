#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e4 + 123;

vector <int> list[MAXN];
int cost[MAXN];
bool mark[MAXN];
int arr[MAXN];

int dfs(int v)
{
    mark[v] = true;
    int sum_pos_sub_tree = 0;
    for(int i=0; i<list[v].size(); i++)
    {
        if (!mark[list[v][i]])
        {
            int nb_cost = dfs(list[v][i]);
            if (nb_cost > 0)
                sum_pos_sub_tree += nb_cost;
        }
    }
    arr[v] = cost[v] + sum_pos_sub_tree;
    //cerr << v << " :  " << vertex_cost << endl;
    return arr[v];
}

int main()
{
    int n, vertex_sum = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int vertex_cost;
        cin >> vertex_cost;
        vertex_sum += vertex_cost;
        cost[i] = vertex_cost;
    }
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        list[a].push_back(b);
        list[b].push_back(a);

    }
    int a = dfs(0);
    cout << *max_element(arr, arr+n) << endl;
    return 0;
}
