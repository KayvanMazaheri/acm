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

const int MAXN = 1e5 + 123;

int n ;
int inp[MAXN] ;
bool msbt[MAXN];
bool brx[MAXN] ;
void input () ;

int main ()
{
    input() ;
    int rslt = inp[n-1] ;
    msbt[n-1] = true ;
    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        if ( rslt >= inp[i] )
            rslt -= inp[i] ;
        else
        {
            rslt = -rslt ;
            rslt += inp[i] ;
            brx[i+1] = true ;
            msbt[i] = true ;
        }
    }
    for ( int i = 0 , j = 0 ; i < n ; i++ )
    {
        if ( brx[i] == true )
            j++ ;
        if ( msbt[i] == true )
        {
            if ( j % 2 == 0 ) 	cout << "+" ;
            else				cout << "-" ;
        }
        if ( msbt[i] == false )
        {
            if ( j % 2 == 0 )	cout << "-" ;
            else				cout << "+" ;
        }
    }
    cout << endl ;
    return 0 ;
}

void input ()
{
    cin >> n ;
    for ( int i = 0 ; i < n ; i ++ )
        cin >> inp[i] ;
}
