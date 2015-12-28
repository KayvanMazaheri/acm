#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 123;

struct bank
{
	int id;
	int money;
	int x;
	bank(int _id, int _x, int _money)
	{
		id = _id;
		money = _money;
		x = _x;
		return;
	}
};

bool op2(bank b1, bank b2)
{
	return (b1.x < b2.x);
}


vector <bank> vec;

int dp_max[MAXN];
int res[MAXN];

int main()
{
	int n, d;
	cin >> n >> d;
	for(int i=0; i<n; i++)
	{
		int x, money;
		cin >> x >> money;
		vec.push_back(bank(i, x, money));
	}
	dp_max[n-1] = n-1;
	for(int i=n-2; i>=0; i--)
	{
		int last = dp_max[i+1];
		if (vec[i].money > vec[last].money)
			dp_max[i] = i;
		else
			dp_max[i] = last;
	}
	for(int i=0; i<n; i++)
	{
		bank buff = vec[i];
		buff.x += d;
		int f_pos = lower_bound (vec.begin(), vec.end(), buff, op2) - vec.begin();
		res[i] = f_pos;
	}
	if (res[0] == n)
	{
		cout << "-1 -1" << endl;
		return 0;
	}
	int problem_res = 0;

	for(int i=0; i<n && res[i] != n ; i++)
		if (vec[i].money + vec[dp_max[res[i]]].money > vec[problem_res].money + vec[dp_max[res[problem_res]]].money)
			problem_res = i;

	cout << problem_res + 1 << " " << dp_max[res[problem_res]] + 1 << endl;
	return 0;
}
