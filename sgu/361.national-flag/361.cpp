#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (i % 3 == 1 && j % 3 == 1)
                cout << "#";
            else if (i % 3 == 0 && j % 3 == 2)
                cout << "#";
            else if (i % 3 == 2 && j % 3 == 0)
                cout << "#";
            else
                cout << "0";
        }
        cout << endl;
    }

    return 0;
}
