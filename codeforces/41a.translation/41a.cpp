#include <iostream>
#include <string>

using namespace std;

string reverse (string s);

int main()
{
    string berland, birland;
    cin >> berland >> birland ;
    if (berland == reverse(birland))
        cout << "YES" << endl ;
    else
        cout << "NO" << endl;
    return 0;
}

string reverse(string s)
{
    string result ;
    for(int i=0; i<s.size(); i++)
    {
        result = s[i] + result ;
    }

    return result ;
}
