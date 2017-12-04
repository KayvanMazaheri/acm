#include <iostream>
#include <string>

using namespace std;

string add (string a, string b)
{
    string result;
    if (b.size() > a.size())
        swap (a, b);
    int extra = a.size() - b.size() ;
    string buffer;
    for (int i=0; i<extra; i++)
        buffer += "0" ;
    buffer += b;
    b = buffer ;
    int r = 0;
    for (int i=a.size()-1; i>=0; i--)
    {
        int num = (int(a[i]-'0') + int(b[i]-'0')) ;
        result = char (( num + r ) %10 +'0') + result;
        r = num/ 10 ;
    }
    if (r)
        result = char(r + '0') + result ;
    return result;
}

int main()
{
    string num ;
    cin >> num ;
    if (num[num.find('.')-1] -'0' == 9)
    {
        cout << "GOTO Vasilisa." << endl;
        return 0;
    }
    if(num[num.find('.')+1] -'0' >= 5)
        if (num[num.find('.')-1] -'0' == 9)
            cout << "GOTO Vasilisa." << endl;
        else
        {
            string result = num.substr(0, num.find('.'));
            result = add(result, "1");
            cout << result << endl ;
        }
    else
    {
        string result = num.substr(0, num.find('.'));
        cout << result << endl;
    }
    return 0;
}
