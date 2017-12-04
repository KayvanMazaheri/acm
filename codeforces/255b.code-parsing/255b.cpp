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
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

const int MAXN = 1e9;
int arr[2];

int main()
{
	string inp;
	cin >> inp;
	for(int i=0; i<inp.size(); i++)
		(inp[i] == 'x' ? arr[0] : arr[1]) ++;
	if (arr[0] > arr[1])
		for(int i=0; i<arr[0] - arr[1]; i++)
			cout << "x";
	else
		for(int i=0; i<arr[1]-arr[0]; i++)
			cout << "y";
	cout << endl;
	return 0;
}
