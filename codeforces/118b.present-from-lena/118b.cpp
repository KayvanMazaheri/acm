#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//freopen ("beads.in","r",stdin);
	//freopen ("present.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1; i < n+2 ; i++)
    {
        for(int j=0; j<=n-i; j++)
            cout << "  " ;
        for (int j=0; j<i; j++)
        {
        	cout << j ;
        	if (i!= 1)
				cout << " " ;
        }

        for (int j=i-2; j>=0; j--)
        {
        	cout << j  ;
        	if (j != 0)
				cout << " ";
        }

        cout << endl ;
    }
    for (int i=n; i > 0 ; i--)
    {
        for(int j=0; j<=n-i; j++)
            cout << "  " ;
        for (int j=0; j<i; j++)
        {
        	 cout << j ;
        	 if (i != 1)
				cout << " ";
        }

        for (int j=i-2; j>=0; j--)
        {
        	cout << j ;
        	if (j != 0)
				cout << " " ;
        }

        cout << endl ;
    }
    cout << endl ;
    return 0;
}
