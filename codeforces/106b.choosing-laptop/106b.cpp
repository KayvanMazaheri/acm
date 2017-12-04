#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e5;

struct laptop
{
	int price;
	int cpu;
	int hdd;
	int ram;
};


bool mark[MAXN];

vector <laptop> vec;
vector <pair <int, int> > result;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		laptop buff;
		cin >> buff.cpu >> buff.ram >> buff.hdd >> buff.price;
		vec.push_back(buff);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if (vec[i].cpu < vec[j].cpu && vec[i].ram < vec[j].ram && vec[i].hdd < vec[j].hdd)
				mark[i] = true;
	for(int i=0; i<n; i++)
		if (!mark[i])
			result.push_back(make_pair(vec[i].price, i));
	sort(result.begin(), result.end());
	cout << result[0].Y + 1 << endl;
	return 0;

}

