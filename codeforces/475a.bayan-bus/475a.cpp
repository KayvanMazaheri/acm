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


int main()
{
	int n;
	cin >> n;
	cout << "+------------------------+" << endl;

	cout << "|" << (n >= 1 ? "O" : "#");
	for (int i = 0; i < 10; ++i)
	{
		cout << ((n-4) > 0 && ((n-4) - 3*i ) > 0 ? ".O" :".#") ;
	}
	cout << ".|D|)" << endl;

	cout << "|" << (n >= 2 ? "O" : "#");
		for (int i = 0; i < 10; ++i)
	{
		cout << ((n-5) > 0 && ((n-5) - 3*i ) > 0 ? ".O" :".#") ;
	}
	cout << ".|.|" << endl;
	cout << "|" << (n >= 3 ? "O" : "#");
	cout << ".......................|" << endl;

	cout << "|" << (n >= 4 ? "O" : "#");
	for (int i = 0; i < 10; ++i)
	{
		cout << ((n-6) > 0 && ((n-6) - 3*i ) > 0 ? ".O" :".#") ;
	}
	cout << ".|.|)" << endl;
	cout << "+------------------------+";
	return 0;
}