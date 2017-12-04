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

#define MAXN (int(1e9))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;


string arr[6] = {"50", "80", "170", "20", "200", "110"};
int num[6] = {1, 2, 2, 4, 4, 5};

int main()
{
    int n;
    cin >> n;
    string result ;
    if (n < 3)
        result = "-1";
    else if (n == 3)
		result = "210";
	else
	{
		n-=4;
		int f = n%6;
		result = "1";
		int z_num = n/6;
		for(int i=0; i<num[f]; i++)
			result += "0";
		for(int i=0; i<z_num; i++)
			result += "000000";
		result += arr[f];

	}
	cout << result << endl;
    return 0;
}
