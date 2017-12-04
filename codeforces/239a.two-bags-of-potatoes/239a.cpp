#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> vec;

int main()
{
	int y, k, n;
	cin >> y >> k >> n;
	for(int i=1; i*k <=n; i++)
		if (i * k - y > 0)
			vec.push_back(i * k - y);
	for(int i=0; i<vec.size(); i++)
		cout << vec[i] << " ";
	if (!vec.size())
		cout << -1;
	cout << endl;
	return 0;
}
