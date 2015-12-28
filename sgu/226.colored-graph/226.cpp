#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

struct bq
{
    int num;
    int depth;
    int color;
} ;

const int MAXN = 1e4;

int target_v = -1;
int problem_result = -1;

bool mark [4][MAXN];
vector <pair <int, int> > list[MAXN];
queue <bq> bfs_queue;

int bfs(int v, int depth, int color)
{
	while(!bfs_queue.empty())
    {
		bq boob = bfs_queue.front();
		v =  boob.num;
		depth = boob.depth;
		color = boob.color;

        if(mark[color][v])
        {
        	bfs_queue.pop();
        	continue;
        }

		mark[color][v] = true;
        if (v == target_v)
            return depth;
        for(int i=0; i<list[v].size(); i++)
            if (!mark[list[v][i].Y][list[v][i].X] && (list[v][i].Y != color))
            {
                bq element;
                element.color = list[v][i].Y;
                element.depth = depth +1;
                element.num = list[v][i].X;
                bfs_queue.push(element);
                //cerr << element.num << " ";
            }
        bfs_queue.pop();
    }
    return -1 ;
}

void input()
{
    int n, e;
    cin >> n >> e;
    target_v = n-1;
    for(int i=0; i<e; i++)
    {
        int a, b, color;
        cin >> a >> b >> color;
        a--;
        b--;
        color --;
        list[a].push_back(make_pair(b, color));
    }
    return ;
}

int main()
{
	input();
	bq first;
	first.color = 3;
	first.depth = 0;
	first.num = 0;
	bfs_queue.push(first);
	cout << bfs(0, 0, 3) << endl;
	return 0;

}
