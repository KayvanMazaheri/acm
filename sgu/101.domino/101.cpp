#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define X first
#define Y second

using namespace std;

vector <int> list[8];
vector <int> result;
map <pair<int, int>, int> edges;
vector <pair<int, int> > inp_edges;
bool mark[200];

void dfs(int v)
{
    for(int i=0; i<list[v].size(); i++)
    {
        if (edges[make_pair(list[v][i], v)])
        {
            edges[make_pair(list[v][i], v)] --;
            edges[make_pair(v, list[v][i])] --;

            dfs(list[v][i]);
        }
    }
    result.push_back(v);
    return;
}

int main()
{
    int n;
    cin >> n ;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
        edges[make_pair(a, b)]++;
        edges[make_pair(b, a)]++;
        inp_edges.push_back(make_pair(a, b));
    }
    int odd_v = 0;
    int v = inp_edges[0].X;
    for(int i=0; i<=6; i++)
        if (list[i].size() % 2)
        {
            odd_v ++;
            v = i;
        }

	dfs(v);
    if (!(odd_v == 0 || odd_v == 2) || result.size() != n+1)
    {
        cout << "No solution" << endl;
        return 0;
    }

    for(int i=0; i<result.size(); i++)
		cerr <<result[i];
	cerr << endl;

    for(int i=0; i<int(result.size()) - 1; i++)
    {
        for(int j=0; j<inp_edges.size(); j++)
            if (!mark[j])
                if (inp_edges[j] == make_pair(result[i], result[i+1]) || inp_edges[j] == make_pair(result[i+1], result[i]))
                {
                    mark[j] = true;
                    cout << j+1 << " " << (inp_edges[j] == make_pair(result[i], result[i+1]) ? "+" : "-") << endl;
                    break;
                }
    }
    return 0;
}
