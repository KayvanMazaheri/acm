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
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 2e5 + 123;
const int INF = 2e6 + 123;

int dis[6][6];
int path[6];
bool mark[6];
long long best_dis = INF;
string best_path;

int main()
{
	path[0] = 0;
	path[4] = 4;
	long long total_dis = 0;
	int n = 5;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		cin >> dis[i][j];
	for(int i=1; i<4; i++)
	{
		mark[i] = true;
		total_dis += dis[0][i];
		path[1] = i;
		for (int j=1; j<4; j++)
		{
			if(mark[j]) continue;

			if((6 - (i+j)) == 2) continue;

			mark[j] = true;

			path[2] = j;
			total_dis += dis[i][j];

			{
				total_dis += dis[j][6 - (i+j)];
				path[3] = 6 - (i+j);

				total_dis +=dis[6 - (i+j)][4];

				if(total_dis < best_dis)
				{
					best_dis = total_dis;
					best_path = "";
					for(int k=0; k<5; k++){
						best_path += char(path[k]+'1');
						if(k!=4) best_path += " ";
					}
				}

				total_dis -=dis[6 - (i+j)][4];

				total_dis -= dis[j][6 - (i+j)];
			}



			total_dis -= dis[i][j];
			mark[j] = false;

		}
		total_dis -= dis[0][i];
		mark[i] = false;
	}

	cout << best_dis << endl;
	cout << best_path << endl;

	return 0;
}
