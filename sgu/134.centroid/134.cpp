// In the Name of God
// SGU 134 - Centroid
// Solution : DFS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct vertex
{
    vector <int> neighbors;
    bool mark ;
    int centroid ;
    int sub ;

};

void input();
int dfs(int v);
int maxSub (int v);
int minCentroid();

vector <int> centroids;
const int MAXN = 16000+2 ;
vertex list [MAXN] ;
int n;

int main()
{
    input();
    dfs(0);
    int minC =  minCentroid();
    //cerr << minC << endl  << endl ;
    for (int i=0; i < n; i++)
    {
        if (list[i].centroid == minC)
			centroids.push_back(i);
    }
    sort(centroids.begin(), centroids.end());

    cout << minC << " " << centroids.size() << endl ;
    for (int i=0; i<centroids.size(); i++)
        cout << centroids[i]+1 << " ";
    cout << endl;

    return 0;
}

void input()
{
    cin >> n;
    int u, v;
    for (int i=0; i< n-1; i++)
    {
        cin >> u >> v;
        u --;
        v-- ;
        list[v].neighbors.push_back(u);
        list[u].neighbors.push_back(v);
    }
}

int dfs(int v)
{
    list[v].mark = true;
    int sub = 1;
    for (int i=0; i<list[v].neighbors.size(); i++)
        if (! list[list[v].neighbors[i]].mark)
            sub += dfs(list[v].neighbors[i]);
    list[v].sub = sub ;
    list[v].centroid = maxSub (v) ;
    return sub;
}

int maxSub (int v)
{
    int maxc = n - list[v].sub;
    for (int i=0; i<list[v].neighbors.size(); i++)
        maxc = max(maxc, list[list[v].neighbors[i]].sub);
    return maxc;
}

int minCentroid()
{
    int MIN = 1e9;
    for (int i=0; i < n; i++)
        MIN = min(list[i].centroid, MIN);
    return MIN;
}
