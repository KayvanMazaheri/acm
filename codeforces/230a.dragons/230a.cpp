#include <iostream>
#include <set>
#include <algorithm>

#define X first
#define Y second

using namespace std;

typedef pair <int, int> point;

struct CMP
{
	bool operator()(const point &a, const point &b) const
	{
		if (a.X == b.X)
			return b.Y < a.Y;
		return a.X < b.X;
	}
};

multiset <point, CMP> my_set;

typedef set <point, CMP> :: iterator ITR;


int main()
{
	long long s = 0;
	int n;
	cin >> s >> n;
	for(int i=0; i<n; i++)
	{
		point inp;
		cin >> inp.X >> inp.Y;
		my_set.insert(inp);
	}

//	for (ITR i = my_set.begin(); i != my_set.end(); i++)
//		cerr << (*i).X << " ";
//	cerr << endl;

	while(!my_set.empty())
	{
		point now = *my_set.begin();
		if (s <= now.X)
		{
			cout << "NO" << endl;
			return 0;
		}
		s += now.Y;
		my_set.erase(my_set.begin());
	}
	cout << "YES" << endl;
	return 0;

}
