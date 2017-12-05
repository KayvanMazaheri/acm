
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
#include <limits>

#define EPS 1e-8
#define PI 3.141592653589793
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

map<int,int> state;

int f(int mat[][15],int usedFil,int usedCol,int n,int fil);

int f2(int mat[][15], int usedFil, int usedCol, int n, int col)
{
	bool flag = false;
	usedCol|=(1<<col);
	int maxx = numeric_limits<int>::min();
	for(int i = 0; i < n ; ++i)
	{
		if(!(usedFil&(1<<i)))
		{
			flag = true;
			maxx = max(f(mat,usedFil,usedCol,n,i),maxx);
		}
	}
	usedCol&= (~(1<<col));
	return flag ? maxx : 0;
}
int f(int mat[][15], int usedFil, int usedCol, int n, int fil)
{
	int actState = ((usedCol<<10)|usedFil);
	map<int,int>::iterator it;
	if( ( it = state.find(actState))!=state.end() )
		return it->second;
	bool flag = false;
	usedFil|=(1<<fil);
	int minn = numeric_limits<int>::max();
	for(int i = 0;i<n;++i)
	{
		int act = 0;
		if(!(usedCol&(1<<i)))
		{
			flag = true;
			minn = min( minn, f2(mat,usedFil,usedCol,n,i)+mat[fil][i]);
		}
	}
	usedFil&=(~(1<<fil));
	return (state[actState] = flag?minn:0);
}
int main(){
	int t,n;
	int mat[15][15];
	int used[15];
	int usedFil,usedCol;
	cin >> t;
	for (int test = 0; test < t; ++test)
	{
		state.clear();
		usedFil = usedCol = 0;
		cin >> n;
		for(int i = 0;i<n;++i){
			for(int j = 0;j<n;++j)
				cin >> mat[i][j];
		}
		int maxx = numeric_limits<int>::min();
		for(int i = 0; i < n ; ++i)
			maxx = max( f( mat, usedFil, usedCol, n, i), maxx);

		cout << maxx << endl;
	}
	return 0;
}
