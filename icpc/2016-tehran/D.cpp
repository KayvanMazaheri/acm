#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 12;

#define X first
#define Y second

int before_count[MAXN][MAXN];
vector<int> graph[MAXN];
int income[MAXN];

int main()
{
	int n, k;
	while(true)
	{
		cin >> n >> k;
		if(!n && !k)
			break;

		// clear everything from previous test cases
		for (int i = 0; i < MAXN; ++i)
		{
			fill(before_count[i], before_count[i]+MAXN, 0);
			graph[i].clear();
			income[i] = 0;
		}

		// read input
		for (int i = 0; i < k; ++i)
		{
			vector<int> algorithm(n);
			for (int j = 0; j < n; ++j)
			{
				cin >> algorithm[j];
				algorithm[j]--;
			}

			// count 
			for (int ii = 0; ii < n; ++ii)
				for (int jj = ii + 1; jj < n; ++jj)
					before_count[algorithm[ii]][algorithm[jj]] ++;
		}

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if(before_count[i][j] > before_count[j][i])
				{
					graph[i].push_back(j);
					income[j]++;
				}

		set<pair<int, int> > st;
		for (int i = 0; i < n; ++i)
			st.insert(make_pair(income[i], i));

		vector<int> result;
		bool has_solution = true;
		
		// topological sort
		while(!st.empty())
		{
			pair<int, int> top = *st.begin();
			if(top.X > 0){
				has_solution = false;
				break;
			}
			st.erase(top);
			int node = top.Y;
			result.push_back(node);

			for (int i = 0; i < graph[node].size(); ++i)
			{
				int v = graph[node][i];
				pair<int, int> update = make_pair(income[v], v);
				st.erase(update);
				update.X --;
				income[v] --;
				st.insert(update);
			}
		}
		if(has_solution)
		{
			for (int i = 0; i < result.size(); ++i)
			{
				if(i) cout << " ";
				cout << result[i] + 1;
			}
			cout << endl;
		} 
		else 
		{
			cout << "No solution" << endl;
		}

	}
	return 0;
}