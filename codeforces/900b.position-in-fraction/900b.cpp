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
map<point, bool> mark;

int solve(int a, int b, int c, int pos) {
  if (mark[make_pair(a, b)])
    return -1;
  mark[make_pair(a, b)] = true;
  int s = a / b;
  if (s == c)
    return pos;
  return solve((a % b) * 10, b, c, pos+1);

}

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  a %= b;
  a *= 10;

  cout << solve(a, b, c, 1) << endl;
	return 0;
}
