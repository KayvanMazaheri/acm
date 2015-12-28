#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 1e2 + 123;

vector <string> accepted;
int marks[MAXN];
int needs[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	string buff;
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
		cin >> marks[i];

	for(int i=0; i<n; i++)
	{
		string uni;
		int total_mark = 0;
		int k;
		getline(cin, buff);
		getline(cin, uni);
		cin >> k;
		for(int j=0; j<k; j++)
		{
			cin >> needs[j];
			needs[j]--;
		}
		for(int j=0; j<k; j++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			int val = marks[needs[j]];
			if(val < x) total_mark += 2;
			else if (x <= val && val < y) total_mark += 3;
			else if (y <= val && val < z) total_mark += 4;
			else if (z <= val) total_mark += 5;
		}
		int s;
		cin >> s;
		for(int j=0; j<s; j++)
		{
			string sub_block;
			getline(cin, buff);
			getline(cin, sub_block);
			int necessary ;
			cin >> necessary;
			if(necessary <= total_mark) accepted.push_back(uni + " " + sub_block);
		}
	}
	for(int i=0; i<accepted.size(); i++)
		cout << accepted[i] << endl;
	if (accepted.empty())
		cout << "Army" << endl;
	return 0;
}
