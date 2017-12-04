#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e4 + 123;
map <string, vector <pair <long long, long long> > > score_table;

typedef map <string, vector <pair <long long, long long> > >::iterator ITR;

int main()
{
	long long MAX_SCORE  = -20000000;
	int n;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		string name;
		int score;
		cin >> name >> score;
		if (score_table[name].size())
			score_table[name].push_back(make_pair(score_table[name][score_table[name].size()-1].X + score, i));
		else
			score_table[name].push_back(make_pair((score), i));
	}

	for (ITR i = score_table.begin(); i != score_table.end(); i++)
	{
		long long val = ((*i).Y)[((*i).Y).size()-1].X;
		MAX_SCORE = max (MAX_SCORE, val);
	}
	cerr << MAX_SCORE << endl;
	string result_name;
	long long result_step;
	for (ITR i = score_table.begin(); i != score_table.end(); i++)
	{
		if (((*i).Y)[((*i).Y).size()-1].X != MAX_SCORE)
			continue;
		for(int j=0; j<((*i).Y).size(); j++)
			if (((*i).Y)[j].X >= MAX_SCORE)
				if (((*i).Y)[j].Y < result_step)
				{
					result_step = ((*i).Y)[j].Y;
					result_name = ((*i).X);
				}
	}
	cout << result_name << endl;
	return 0;


}
