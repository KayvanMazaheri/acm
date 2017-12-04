#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 3)
        cout << -1 ;
    else
    {
        cout << 3;
        for(int i=1; i<n; i++)
            cout << " " << (i % 2 ? 5: 1);
    }
    cout << endl;
    return 0;
}
