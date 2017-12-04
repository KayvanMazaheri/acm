//In the name of God
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <iomanip>
#define FX(x) fixed << setprecision((x))

using namespace std;

double n,d,a,v,k,ma;

int main()
{
    cin>>n>>a>>d;
    for(int i=0;i<n;i++)
    {
        cin>>k>>v;
        if((v/a)*(v/a)/2.0*a>=d)
        {
            ma=max(sqrt(d/a*2.0)+k,ma);
            cout<< FX (10) <<ma<<endl;
        }
        else
        {
            ma=max((d+a*(v/a)*(v/a)/2)/v+k,ma);
            cout<< FX (10) <<ma<<endl;
        }
    }
    return 0;
}
