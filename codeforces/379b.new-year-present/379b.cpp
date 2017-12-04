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
const int MAXN = 1e4;
int arr[MAXN];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	for(int i=0; i<n; i++){
	 for(int j=0; j<arr[i]; j++)
	{
		cout << "P";
		if (i != n-1)
			cout << "RL";
		else
			cout << "LR";
	}
	if (i != n-1) cout << "R";
	}
	cout << endl;

	return 0;
}
