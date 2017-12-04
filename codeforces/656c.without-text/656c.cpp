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


int alphaIndex(char c){
	if( 'A' <= c && c <= 'Z')
		c = c - 'A' + 'a';
	if( 'a' <= c && c <= 'z')
		return c - 'a' + 1;
	return c - '0';
}

int main()
{
	string s;
	cin >> s;
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		bool b1, b2, b3, b4;
		b1 = '@' < c;
		b2 = '[' > c;
		b3 = '`' < c;
		b4 = '{' > c;

		int in1, in2;
		in1 = (int) (b1 && b2);
		in2 = (int) (b3 && b4);

		int index = alphaIndex(c);

		int h1, h2;
		h1 = in1 * index;
		h2 = in2 * index;

		res += h1 - h2;
	}

	cout << res << endl;

	return 0;
}