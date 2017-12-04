#include <iostream>
#include <map>
using namespace std;

map <int, int> my_map;

int main()
{
	int a, b, m, r0;
	cin >> a >> b >> m >> r0;
	for(int r = r0, lev = 0; ; r = (r * a + b) % m, lev++)
	{
		if (my_map.find(r) != my_map.end())
		{
			cout << lev - my_map[r] << endl;
			return 0;
		}
		my_map[r] = lev;
	}
}
