#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define X first
#define Y second

using namespace std;

struct junction
{
//     memory = 1 + 4 + 4 + 4 = 13 bytes;
    bool color;				// red = 0, blue = 1
    int remain_time;
    int red_delay;
    int blue_delay;
};

const int MAXN = 3e2 + 123 ;
const unsigned long long INF = (unsigned long long) (-1) / 2;
int source_junction ;
int target_junction ;

vector <pair<int, int> > list[MAXN];	// save the junctions graph
junction info[MAXN];					// save information of all junctions int time = 0
int dij_dp[MAXN];						// to save father of each vertex
unsigned long long dij_dis[MAXN];		// to save minimum time required to get into junction[i]

struct CMP
{
    bool operator () ( const int &a , const int &b ) const
    {
        if ( dij_dis[a] == dij_dis[b] ) return a<b ;
        return dij_dis[a] < dij_dis[b] ;
    }
};

set <int, CMP> dij_set;

void get_input();
void print_output();
long long get_stop_time (junction j1, junction j2);
junction junction_in_time (junction j, long long time);
void dij();
void prepare();

int main()
{

    get_input();
    prepare();
    dij();
    print_output();
    return 0;
}

void print_output()
{
    if (dij_dis[target_junction] == INF)
    {
        cout << 0 << endl;
        return ;
    }

    cout << dij_dis[target_junction] << endl;
    vector <int> route;
    route.push_back(target_junction);

    while(dij_dp[route[route.size()-1]] != -1)
        route.push_back(dij_dp[route[route.size()-1]]);
    reverse (route.begin(), route.end());
    for(int i=0; i<route.size(); i++)
        cout << route[i]+1 << " ";
    cout << endl;
    return;
}

void dij()
{
    while (!dij_set.empty())
    {
        int min_v = *dij_set.begin();
        dij_set.erase(dij_set.begin());
        for(int i=0; i<list[min_v].size(); i++)
        {
            int adj_num = list[min_v][i].X;
            int adj_dis = list[min_v][i].Y;

            junction j1 = junction_in_time(info[min_v], dij_dis[min_v]);
            junction j2 = junction_in_time(info[adj_num], dij_dis[min_v]);
            long long stop_time = get_stop_time(j1, j2);
            if (stop_time == -1)
                continue;
            long long new_dis = adj_dis + stop_time + dij_dis[min_v];
            if (new_dis < dij_dis[adj_num])
            {
                dij_set.erase(adj_num);
                dij_dis[adj_num] = new_dis;
                dij_dp[adj_num] = min_v;
                dij_set.insert(adj_num);
            }
        }
    }
    return ;
}

long long get_stop_time (junction j1, junction j2)
{
	if (j1.color == j2.color)
		return 0;
    if (j1.remain_time == j2.remain_time && j1.blue_delay == j2.red_delay && j1.red_delay == j2.blue_delay)
        return -1;
    long long require_time = 0;
    while (j1.color != j2.color)
    {
        j1 = junction_in_time(j1, 1);
        j2 = junction_in_time(j2, 1);
        require_time ++;
    }
    return require_time;
}

void prepare()
{
    for(int i=0; i<MAXN; i++)
    {
        dij_dis[i] = INF;
        dij_dp[i] = -1;
        dij_set.insert(i);
    }
    dij_set.erase (source_junction);
    dij_dis[source_junction] = 0;
    dij_set.insert(source_junction);
    return;
}

junction junction_in_time (junction j, long long time)
{
    junction result = j;
    time %= (j.blue_delay + j.red_delay);
    if (time < j.remain_time)
    {
        result.remain_time -= time;
        return result;
    }
    time -= j.remain_time;
    result.color = !result.color;
    result.remain_time = (result.color?result.blue_delay:result.red_delay);
    if (!time)
        return result;
    if (time < result.remain_time)
    {
        result.remain_time -= time;
        return result;
    }
    time -= result.remain_time;
    result.color = !result.color;
    result.remain_time = (result.color?result.blue_delay:result.red_delay);
    if (!time)
        return result;
    if (time < result.remain_time)
    {
        result.remain_time -= time;
        return result;
    }
    time -= result.remain_time;
    result.color = !result.color;
    result.remain_time = (result.color?result.blue_delay:result.red_delay);
    if (!time)
        return result;
    cerr << "Error #001" << endl;
}

void get_input()
{
    cin >> source_junction >> target_junction ;
    source_junction --;
    target_junction --;
    int n, e;
    cin >> n >> e;
    for(int i=0; i<n; i++)
    {
//         get junctions information
        char c;
        int rc, tb, tr;
        cin >> c >> rc >> tb >> tr;
        junction buff;
        buff.color = (c == 'B');
        buff.remain_time = rc;
        buff.blue_delay = tb;
        buff.red_delay = tr;
        info[i] = (buff);
    }
    for(int i=0; i<e; i++)
    {
        int a, b, len;
        cin >> a >> b >> len;
        a--;
        b--;
        list[a].push_back(make_pair(b, len));
        list[b].push_back(make_pair(a, len));
    }
    return;
}
