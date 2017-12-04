#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

vector <pair<int , int > > vec;

int main()
{
	long long vasya = 0, petya = 0;
	int n, m;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(make_pair(inp, i));
	}
	sort(vec.begin(), vec.end());
	cin >> m;
	for(int i=0; i<m; i++)
	{
		int query;
		cin >> query;
		query --;
		petya += n - vec[query].Y ;
		vasya += vec[query].Y + 1 ;
	}
	cout << vasya << " " << petya << endl;
	return 0;


}
