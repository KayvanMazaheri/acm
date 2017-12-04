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

#define MAXN (int(1e5 + 123))
#define EPS 1e-8
#define PI 3.141592653589793
#define point pair <int , int>
#define X first
#define Y second
#define FX(x) fixed << setprecision((x))

using namespace std;

int arr[MAXN];
int str[MAXN];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	arr[n] = 100000+ 123;
	int last_genre = -1;
	int this_genre = arr[0];
	for(int i=0; i<=n; i++)
	{
		if (arr[i] == this_genre)
			continue;
		//cerr << i << " : " << this_genre << endl;
		if (last_genre == -1)
			str[this_genre] ++;
		else if (last_genre == arr[i])
			str[this_genre] += 2;
		else
			str[this_genre] ++;
		last_genre = this_genre;
		this_genre = arr[i];

	}
//	if  (arr[0] != arr[1])
//		str[arr[0]] ++;
//	for(int i=1; i<n; i++)
//	{
//		if (arr[i] == this_genre)
//			continue;
//		//if (arr[i] == last_genre || last_genre == -1)
//		{
//			//cerr <<i << " : " << arr[i] << endl;
//			str[arr[i]] ++;
//			if (arr[i])
//			last_genre = this_genre;
//			this_genre = arr[i];
//		}
//	}
	//str[this_genre] ++;
	int mx_val = -1;
	int mx_i = -1;
	for(int i=0; i<k+3; i++){
		//cerr << str[i] << " ";
		if (str[i] > mx_val)
		{
			mx_i = i;
			mx_val = str[mx_i];
		}
	}
	//cerr << endl;
	cout << mx_i << endl;
	return 0;
}
