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

int neg = 0;
int pos = 0;
int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    point p;
    cin >> p.X >> p.Y;
    if(p.X > 0)
    pos++;
    else
    neg++;

  }
  if (pos <= 1 || neg <= 1) {
    cout << "Yes" << endl;
  }
  else
    cout << "No" << endl;
	return 0;
}
