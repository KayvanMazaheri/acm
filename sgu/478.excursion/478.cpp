	#include <iostream>
#include <vector>
using namespace std;

vector <int> vec;

int main()
{
	int b, g, n;
	cin >> b >> g ;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(inp);
	}
	int start = g;
	int now = g;
	for(int i=0; i<n; i++)
	{
		if (vec[i] - now > 0)
			b -= vec[i] - now;
		else
			g -= now - vec[i];
		if (b < 0 || g < 0)
		{
			cout << "ERROR" << endl;
			return 0;
		}
		now = vec[i];
	}
	now = start;
	//cerr << start << endl;
	for(int i=0; i<n; i++)
	{
		//cerr << i << " : " << now << endl;
		if (vec[i] - now > 0)
			cout << vec[i] - now << " 0" << endl;
		else
			cout << "0 " <<  now - vec[i] << endl;
			now = vec[i];
	}
	return 0;
}
