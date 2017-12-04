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

int arr[10];

int main()
{
	for(int i=0; i<9; i++)
		cin >> arr[i];
	int a[10];
	int buff = ((arr[5] + arr[7]) - (arr[1] + arr[3])) / 2;
	int buff_2 = arr[2] + arr[6];
	a[0] = buff + buff_2;
	a[0] /=2;
	arr[0] = a[0];
	a[8] = -1 * (buff - a[0]);
	arr[8] = a[8];
	arr[4] = (arr[0] + arr[1] + arr[2]) - (arr[3] + arr[5]);
	for(int i=0; i<9; i++)
	{
		cout << arr[i] << " ";
		if ((i+1) % 3 == 0)
			cout << endl;
	}
	return 0;

	return 0;
}
