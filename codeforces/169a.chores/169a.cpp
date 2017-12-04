#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#define MAXN (int(1e9))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

vector <long long> chore;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	for(int i=0; i<n; i++)
	{
		long long inp;
		cin >> inp;
		chore.push_back(inp);
	}
	if (a+b != n)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(chore.begin(), chore.end());
	//int bc = chore[b-1];
	int result = chore[b] - chore[b-1];
	cout << result << endl;
	return 0;
}
