#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (!a || !b)
    {
        cout << 0 << endl;
        return 0;
    }
    int move = 0;
    for (move =0; a != b; )
    {
        if ((a+b) % 2)
        {
            cout << -1 << endl;
            return 0;
        }
        if (a%2)
        {
            if (b < a)
                swap(a, b);
            b-=a;
            a*=2;
            move ++;

        }
        a/=2;
        b/=2;
        //cerr << a << " " << b << endl;
    }
    cout << move + 1 << endl;
    return 0;
}
