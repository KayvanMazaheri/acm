#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e3;

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
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int result = 0;
	for (int i=0; i<n; i++)
	{
		if (mark[i])
			continue;
		result += !(dfs(i, 0));
	}
	cout << ((n-result)%2?result+1:result) << endl;
	return 0;
}
