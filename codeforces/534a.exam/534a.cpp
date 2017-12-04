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
const int MAXN = 2e5 + 123;

vector <int> v1, v2;

int main()
{
	v1.push_back(4);
	v1.push_back(2);
	v2.push_back(1);
	v2.push_back(3);
	int n;
	cin >> n;
	if(n < 3)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if(n == 3)
	{
		cout << 2 << endl;
		cout << 1 << " " << 3 << endl;
		return 0;
	}

	cout << n << endl;
	for (int i = 5; i <= n; ++i)
	{
		if(i % 2)
		v2.push_back(i);
	else
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); ++i)
		cout << v1[v1.size()-1-i] << " ";
	for (int i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
		

	return 0;
}