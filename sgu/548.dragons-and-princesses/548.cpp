#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define MAXN (int(1e6))
#define X first
#define Y second

using namespace std;

set <pair <int, int> > result;
set <pair <int, int> >::iterator it;

int main()
{
	int n;
	cin >> n;

	for(int i=0; i<n-2; i++)
	{
		char c;
		int val;
		cin >> c >> val;
		if (c == 'd')
			result.insert(make_pair(val, i));
		if (c == 'p')
			while (val <= result.size())
				result.erase(result.begin());
	}
	char c;
	int val;
	cin >> c >> val;
	if (val > result.size())
	{
		cout << -1 << endl;
		return 0;
	}
	long long MAX_SUM = 0;
	for(it=result.begin(); it!=result.end(); it++)
		MAX_SUM += (*it).X;

	cout << MAX_SUM << endl;
	cout << result.size() << endl;

	vector <int> dragon_num;

	for(it=result.begin(); it!=result.end(); it++)
		dragon_num.push_back((*it).Y);

	sort(dragon_num.begin(), dragon_num.end());
	for(int i=0; i<dragon_num.size(); i++)
		cout << dragon_num[i] +2 << " ";
	cout << endl;

	return 0;
}
