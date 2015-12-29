// In the name of God
// SGU, Problem Number 149
// Computer Network
// Solution : DFS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void input() ;
int max_dis();
void clear();

const int MAXN = 100 * 100 + 12 ;				// maximum input
bool mark[MAXN] ;								// marking members
vector <pair <int, int> > tree [MAXN] ;			// to save data as a tree
int dis[MAXN] ;									// to save distance of each node from the root
int n;											// number of computers

int S [MAXN];									// longest cable of each computer

// Deep First Search
void dfs(int x, int h)
{
    mark[x] = true ;
    for(int i=0; i < tree[x].size(); i++)
        if (!mark[tree[x][i].first])
            dfs(tree[x][i].first, h+tree[x][i].second);
    dis[x] = h;
}

int main()
{
    cin >> n;
    input();

    dfs(0,0);
    int sare1 = max_dis();
    clear();
    dfs(sare1, 0) ;
    int sare2 = max_dis();
    int dis_sare1[MAXN];
    for(int i=0; i<n; i++)
        dis_sare1[i] = dis[i];
    clear();
    dfs(sare2, 0);

    // Print output
    for (int i=0; i<n; i++)
    {
        S[i] = max(dis[i],dis_sare1[i]) ;
        cout << S[i] << endl ;
    }

	return 0;
}

// Read input from keyboard
void input()
{
    for(int i=1; i<n; i++)
    {
        int parent; int weight;
        cin >> parent >> weight ;
        parent -- ;
        tree[i].push_back(make_pair(parent, weight));
        tree[parent].push_back(make_pair(i, weight));
    }
}


// Returns maximum element of "dis" array
int max_dis()
{
    pair <int, int> maximum;
    maximum.first = 0;
    maximum.second = 0;
    for (int i=0; i<MAXN; i++)
    {
        if(dis[i]>maximum.second)
        {
        	maximum.first = i ;
        	maximum.second = dis[i];
        }

    }

    return maximum.first ;
}

//clear data from last DFS
void clear()
{
    for (int i=0; i<MAXN; i++)
    {
    	dis[i] = 0;
    	mark[i] = false ;
    }

}
