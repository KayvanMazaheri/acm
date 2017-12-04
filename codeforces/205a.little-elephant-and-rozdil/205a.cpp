#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

vector <pair <int, int> > vec;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(make_pair(inp, i));
	}
	sort (vec.begin(), vec.end());
	if (vec.size() > 1 && vec[0].X == vec[1].X)
		cout << "Still Rozdil" << endl;
	else
		cout << vec[0].Y + 1 << endl;
	return 0;
}
