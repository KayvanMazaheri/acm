#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

vector<int> logos;
map<int, int> votes[3];

vector<int> filter(const vector<int> &input, int(*score)(int))
{
	vector<int> filtered;
	int max_score = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		int myScore = (*score)(input[i]);
		if(myScore > max_score){
			filtered.clear();
			max_score = myScore;
		}
		if(myScore == max_score)
			filtered.push_back(input[i]);
	}
	return filtered;
}

int scoreFunction1(int logo) { return 3 * votes[0][logo] + 2 * votes[1][logo] + votes[2][logo]; }
int scoreFunction2(int logo) { return votes[0][logo] ; }
int scoreFunction3(int logo) { return votes[1][logo] ; }

int main()
{
	int n;
	while(true)
	{
		cin >> n;
		if(!n)
			break;

		logos.clear();
		votes[0].clear();
		votes[1].clear();
		votes[2].clear();

		for (int i = 0; i < n; ++i)
		{
			int d;
			cin >> d;
			for (int j = 0; j < d; ++j)
			{
				int inp;
				cin >> inp;
				logos.push_back(inp);
				votes[j][inp] ++;
			}
		}
		sort(logos.begin(), logos.end());
		logos.resize(distance(logos.begin(), unique (logos.begin(), logos.end())));

		logos = filter(logos, scoreFunction1);
		logos = filter(logos, scoreFunction2);
		logos = filter(logos, scoreFunction3);

		for (int i = 0; i < logos.size(); ++i)
		{
			if(i) cout << " ";
			cout << logos[i];
		}
		cout << endl;
	}
	return 0;
}