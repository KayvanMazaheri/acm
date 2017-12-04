#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define X first
#define Y second

using namespace std;

vector < pair <int, int> > vec;

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(make_pair(inp, i));
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	cout << vec[k-1].X << endl;
	for(int i=0; i<k; i++)
		cout << vec[i].Y + 1 << " ";
	cout << endl;
	return 0;
}
