#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN (int(4e3 + 123))
#define X first
#define Y second

using namespace std;

int num[MAXN];
vector <int> cost[MAXN];
vector <pair<int, int> > dumbbells;

int main()
{
	int n, k;
	cin >> n >> k;
	long long result_cost = 0;
	int result_num = 0;
	for(int i=0; i<n; i++)
	{
		int m, c;
		cin >> m >> c;
		num[m] ++;
		cost[m].push_back(c);
	}
	for(int i=0; i<MAXN; i++)
		sort(cost[i].begin(), cost[i].end());
	//cerr << "#1" << endl;
	for(int i=0; i<MAXN; i++)
		dumbbells.push_back(make_pair(num[i], i));
	sort(dumbbells.begin(), dumbbells.end());
	//cerr << "#2" << endl;
	int MAX_SET = dumbbells[dumbbells.size()-k].X;

	if (MAX_SET < 1)
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}

	vector <int> acc_mass;
	vector <int> acc_mass_cost;
	for(int i=0; i<MAXN; i++)
		if (dumbbells[i].X >= MAX_SET)
			acc_mass.push_back(dumbbells[i].Y);
	//cerr << "#3" << endl;

	for(int i=0; i<acc_mass.size(); i++)
	{
		int max_cost = 0;
		//cerr << cost[acc_mass[i]].size()-MAX_SET << endl;
		//cerr << acc_mass[i] << " " << cost[acc_mass[i]].size() << " " << MAX_SET << endl;
		for(int j=cost[acc_mass[i]].size()-1; j>= (int(cost[acc_mass[i]].size())-MAX_SET); j--)
			max_cost += cost[acc_mass[i]][j];
		acc_mass_cost.push_back(max_cost);
	}


	//cerr << "#4" << endl;
	sort(acc_mass_cost.begin(), acc_mass_cost.end());
	result_num = MAX_SET;
	for(int i=acc_mass_cost.size()-1; i >= (int(acc_mass_cost.size())-k); i--)
		result_cost += acc_mass_cost[i];
	cout << result_num << " " << result_cost << endl;
	return 0;
}
