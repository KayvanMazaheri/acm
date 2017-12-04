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

int main()
{
    int n;
    int result = 0;
    string s;
    cin >> n >> s;
    for(int i=0; i<n;)
    {
        int j;
        for(j = i; s[i] == s[j] && j  < n; j++, result++);
        result--;
        i = j;
    }
    cout << result << endl;
    return 0;
}
