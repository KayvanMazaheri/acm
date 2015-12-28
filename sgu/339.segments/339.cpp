#include <iostream>
#include <algorithm>
#include <set>

#define X first
#define Y second

using namespace std;

typedef multiset<pair <int, int> >::iterator ITR;
multiset <pair <int, int> > my_set;

int main()
{
	char  query;
	while (cin >> query)
	{
		int l, r;
		cin >> l >> r;
		if (query == '-')
			if (my_set.find(make_pair (r, l)) != my_set.end())
					my_set.erase (my_set.find(make_pair (r, l)));
		if (query == '+')
		{
			int result = 0;
			for(ITR i = my_set.begin(); (*i).X <= r && i!=my_set.end(); i++)
				if ((*i).Y >= l)
					result ++;
			my_set.insert(make_pair (r, l));
			cout << result << endl;
		}
	}
}
