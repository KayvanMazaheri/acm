#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector <int> pos;
vector <int> neg;

int main()
{
	string a, b;
	cin >> a >> b;
	int ap = 0, bp = 0;
	for(int i=0; i<a.size(); i++)
		if (a[i] == '+')
			ap ++;
	for(int i=0; i<b.size(); i++)
		if (b[i] == '+')
			bp ++;
	if (ap != bp || a.size() != b.size())
	{
		cout << -1 << endl;
		return 0;
	}
	int move = 0;
	for(int i=0; i<a.size(); i++){
		if (a[i] != b[i])
		{
			if ( a[i] == '+')
				pos.push_back(i);
			if (a[i] == '-')
				neg.push_back(i);
		}
	}
	if (pos.size() != neg.size())
	{
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<pos.size(); i++)
		move += abs(pos[i] - neg[i]);
	cout << move << endl;
	return 0;
}
