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

bool sort_f(point a, point b)
{
	if(a.Y == b.Y) return a.X < b.X;
	return a.Y < b.Y ;

}

int main()
{
    int T;
    cin >> T;
    for(int test = 0; test < T; test++)
    {
        point inp;
        vector< point > vec;

        while(1)
        {
            cin >> inp.X >> inp.Y;
			if(inp.X == inp.Y && inp.X == 0) break;
			vec.push_back(inp);
        }
        sort(vec.begin(), vec.end(), sort_f);
        point last = make_pair(-1, -1);
        int result = 0;
        for(int i=0; i<vec.size(); i++)
		{
			if(vec[i].X >= last.Y)
			{
				result ++;
				last = vec[i];
			}
		}
		cout << result << endl;

    }
    return 0;
}
