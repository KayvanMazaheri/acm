// K1
// :)

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>

#define EPS 1e-8
#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

typedef pair<int, int> point;
typedef set<int>::iterator ITR;
const int MAXN = 1e6;

vector <point> vec;
int arr[MAXN];

int main()
{
	int n;
	int cur = 0;
	cin >> n;
	for (int i=0; i<n; i++)
	{
		int inp;
		cin >> inp;
		vec.push_back(make_pair(inp, i));
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<n; i++)
	{
		if (vec[i].X > cur)
			cur = vec[i].X;
		arr[vec[i].Y] = cur;
		cur++;
	}
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
