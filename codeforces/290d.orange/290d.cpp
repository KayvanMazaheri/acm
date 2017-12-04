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
const int MAXN = 1e9;

char low(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return c - 'A' + 'a';
	return c;
}

char up(char c)
{

if ((c >= 'a' && c <= 'z'))
		return c - 'a' + 'A';
	return c;
}

int main()
{
	string a;
	int f;
	cin >> a >> f;
	char g;
	string result;

	for(int i=0; i<a.size(); i++)
		a[i] = low(a[i]);
	for(int i=0; i<a.size(); i++)
	{
		g = a[i];
		if (int(g) < f+97)
			result += up(g);
		else
			result += low(g);
	}
	cout << result << endl;
	return 0;
}
