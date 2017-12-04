#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAXN = 1e5;
bool damage[MAXN] ;
int main()
{
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	for (int i=k-1; i<d; i+=k)
		damage[i] = true ;
	for (int i=l-1; i<d; i+=l)
		damage[i] = true ;
	for (int i=m-1; i<d; i+=m)
		damage[i] = true ;
	for (int i=n-1; i<d; i+=n)
		damage[i] = true ;
	int damaged = 0;
	for (int i=0; i<d; i++)
		if (damage[i])
			damaged ++ ;
	cout << damaged << endl ;

	return 0;
}
