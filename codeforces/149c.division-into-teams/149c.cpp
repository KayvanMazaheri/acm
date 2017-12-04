#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 333 ;

pair <int, int> arr[MAXN];
vector <int> team1;
vector <int> team2;

int team1Total = 0;
int team2Total = 0;

int main()
{
	int n;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		arr[i] = make_pair(inp, i);
	}

	sort (arr, arr+n);
	for (int i=0; i<n; i++)
	{
		if(team1Total < team2Total)
		{
			team1.push_back(arr[i].second);
			team1Total += arr[i].first ;
		}
		else
		{
			team2.push_back(arr[i].second);
			team2Total += arr[i].first;
		}
	}
	cout << team1.size() << endl ;
	for (int i=0; i<team1.size(); i++)
		cout << team1[i]+1 << " ";
	cout << endl ;
	cout << team2.size() << endl ;
	for (int i=0; i<team2.size(); i++)
		cout << team2[i]+1 << " ";
	cout << endl ;
	return 0;
}
