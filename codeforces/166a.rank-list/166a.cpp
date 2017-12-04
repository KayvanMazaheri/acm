#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#define MAXN (int(1e2))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

vector < pair < point, int > > teams;
int places[MAXN];
vector <int> teamPlace[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	k--;
	for(int i=0; i<n; i++)
	{
		int p, t;
		cin >> p >> t;
		teams.push_back(make_pair(make_pair(MAXN - p, t), i));
	}
	sort(teams.begin(), teams.end());
	for(int i=0; i<n; )
	{
		int l = 0;
		for(int j=i; teams[j].X.X == teams[i].X.X && teams[j].X.Y == teams[i].X.Y; j++)
			l ++;
		for(int j=i; j<=i+l; j++)
			places[j] = l;
		i+=l;
	}
	cout << places[k] << endl;
	return 0;
}
