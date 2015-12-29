#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <pair<int, int> > list;

int main()
{
    int n, result = 0;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		list.push_back(make_pair(a, b));
	}
	//sort(list.begin(), list.end());
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (list[j].first < list[i].first && list[i].second < list[j].second)
			{
				result ++;
				break;
				cerr << list[i].first << ", " << list[i].second << "  is in   " << list[j].first << ", " << list[j].second << endl;
			}
	cout << result << endl;
	return 0;
}
