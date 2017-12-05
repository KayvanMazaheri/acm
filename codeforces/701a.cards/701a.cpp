#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
#define X first
#define Y second

int main(){

	int n;
	cin >> n;
	vector<point> vec;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		vec.push_back(make_pair(num, i+1));
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n/2; ++i)
		cout << vec[i].Y << " " << vec[n-1-i].Y << endl;
	return 0;
}
