#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int p,q,l,r;
    cin>>p>>q>>l>>r;
    vector < pair <int , int>  > Z;
    vector < pair <int , int> > X;
    int a,b;
    pair <int, int>t;
    for(int i=0 ; i<p ; i++)
    {
        cin>>a>>b;
        t=make_pair(a,b);
        Z.push_back(t);
    }
    for(int i=0 ; i<q; i++)
    {
        cin>>a>>b;
        t=make_pair(a,b);
        X.push_back(t);
    }
    int ans=0;
    int best=0;
    while(l<=r)
    {
        ans=0;
        for(int i=0 ; i<q ;i++)
        {
            for(int j=0 ; j<p ; j++)
            {
                if( X[i].first+l <= Z[j].second  && X[i].second+l >= Z[j].first)
                {
                    ans++;
                    break;
                }
            }
        }
        best += (ans > 0);
        l++;
    }
    cout<<best<<endl;
}
