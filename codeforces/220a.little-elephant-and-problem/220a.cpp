#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

#define X first
#define Y second

using namespace std;

const int MAXN = 1e9 + 123;

//vector < pair <int, int> > vec;
bitset <MAXN> mark;


int main()
{
	vector <int> vec, res;
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(inp);
		res.push_back(inp);
	}
	sort (vec.begin(), vec.end());
	int result = 0;
	for(int i=0; i<n; i++)
		if (vec[i] != res[i])
			result++;
		cout << (result>2?"NO":"YES") << endl;
		return 0;
//	for(int i=0, f = 0; i<n; i++)
//	{
//		int inp;
//		cin >> inp;
//		if (mark[inp])
//			continue;
//		mark[inp] = true;
//		vec.push_back(make_pair(inp, f));f++;
//	}
//	sort(vec.begin(), vec.end());
//	int res = 0;
//	for(int i=0; i<vec.size(); i++)
//		if (vec[i].Y != i)
//			res++;
//	cout << (res>2?"NO":"YES") << endl;
//	return 0;

}
