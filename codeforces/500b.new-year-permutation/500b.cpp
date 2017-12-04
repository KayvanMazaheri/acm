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
const int MAXN = 2e3 + 123;

int arr[MAXN];
char mx[MAXN][MAXN];
bool mark[MAXN];

// struct less_than_key
// {
//     inline bool operator() (const int &a, const int & b)
//     {
//         return (a < b) && mx[a-1][b-1] == '1';
//     };
// };

int par[MAXN];

int find(int n)
{
	if (par[n] == n)
		return n;
	return par[n] = find(par[n]);
}

void join(int a, int b)
{
	int par_a = find(a);
	int par_b = find(b);

	par[par_a] = par_b;
	return;
}
int main()
{
	for (int i = 0; i < MAXN; ++i)
	{
		par[i] = i;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> mx[i][j];
			if(mx[i][j] == '1')
				join(i, j);
		}

	for (int i = 0; i < n; ++i)
	{
		int candidate = 999;
		for (int num = 0; num < n; ++num)
			if ((!mark[arr[num]]) && (find(num) == find(i)) && (arr[num] < candidate))
				candidate = arr[num];
		mark[candidate] = true;
		cout << candidate << " ";
	}
	cout << endl;
	return 0;
}