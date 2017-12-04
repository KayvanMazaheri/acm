#include <iostream>
#include <map>
using namespace std;

typedef map<int, int>::iterator ITR;

map <int, int> ID;

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		ID[inp]++;
	}
	int result = 0;
	bool flag = false;
	for(ITR i = ID.begin(); i != ID.end(); i++)
	{
		if (i->first == 0) continue;
		else if (i->second == 2) result ++;
		else if (i->second > 2 ) flag = true;
	}
	cout << (flag ? -1 : result ) << endl;
	return 0;
}
