#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 50;

vector <int> db[MAXN];
vector <int> query[MAXN];
bool mark[MAXN];

bool exist(int a, int in)
{
	for (int i=0; i<db[in].size(); i++)
		if (db[in][i] == a)
			return true;
	return false;
}

bool good(int d, int q)
{
	for(int i=0; i<query[q].size(); i++)
	{
		if (query[q][i] < 0)
			if (exist(abs(query[q][i]), d))
				return false;
		if (query[q][i] >=0)
			if (!exist((query[q][i]), d))
				return false;
	}
	return true;
}

int main()
{
	int n, m;
	cin >> m >> n;
	for(int i=0; i<m; i++)
	{
		int k;
		cin >> k;
		for(int j=0; j<k; j++)
		{
			int inp;
			cin >> inp;
			db[i].push_back(inp);
		}
	}
	for(int i=0; i<n; i++)
	{
		int k;
		cin >> k;
		for(int j=0; j<k; j++)
		{
			int inp;
			cin >> inp;
			query[i].push_back(inp);
		}
	}
	//cerr << "______________________________" << endl;
	for(int i=0; i<n; i++)
	{
		int result = 0;
		fill(mark, mark+m, 0);
		for(int j=0; j<m; j++)
			if (good(j, i))
			{
				result ++;
				mark[j] = true;
			}
		cout<< result << endl;
		for(int j=0; j<m; j++)
			if (mark[j])
			{
				cout << db[j].size() << " ";
				for(int l=0; l<db[j].size(); l++)
					cout << db[j][l] << " ";
				cout << endl;
			}
	}
}
