#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAXN = 30 * 30 + 100;

bool arr[MAXN];

vector <int> vec [MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0; i<k; i++)
	{
		int p;
		cin >> p;
		arr[p] = true;
		vec[i].push_back(p);
	}
	int num = 0;
	for(int i=1; i<= n*k; i++)
	{
		if (vec[num].size() == n)
			num ++;
		if (!arr[i])
			vec[num].push_back(i);
	}
	for(int i=0; i<k; i++)
		sort(vec[i].begin(), vec[i].end());
	for(int i=0; i<k; i++)
	{
		for(int j=0; j<vec[i].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	return 0;

}
