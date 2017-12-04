#include <iostream>
#include <string>

using namespace std;

int rank(char c)
{
    if (c == '6')
        return 1;
    else if (c == '7')
        return 2;
    else if (c == '8')
        return 3;
    else if (c == '9')
        return 4;
    else if (c == 'T')
        return 5;
    else if (c == 'J')
        return 6;
    else if (c == 'Q')
        return 7;
    else if (c == 'K')
        return 8;
    else if (c == 'A')
        return 9;
    else
        return 999;
}

int main()
{
    char suit ;
    string a, b;
    cin >> suit >> a >> b;
    if (a[1] == suit)
    {

        if (b[1] == suit)
        {
            if(rank(a[0]) > rank(b[0]) && a[1] == b[1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    else
    {
        if(b[1] == suit)
            cout << "NO" << endl;
        else
        {
            if(rank(a[0]) > rank(b[0]) && a[1] == b[1])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
