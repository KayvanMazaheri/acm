#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int result = 0;
    int f_s = 0;
    int s_f = 0;

    for (int i=0; i<b.size(); i++)
    {
        if(a[i] != b[i])
        {
            if(a[i] == '7')
                s_f++;
            else
                f_s ++;
        }
    }
    //cerr << s_f << " " << f_s << endl;
    if (s_f == f_s)
        result = s_f;
    else
    {
        if(s_f > f_s)
        {
            result += s_f - f_s ;
            result += f_s;
        }
        else
        {
            result += f_s - s_f ;
            result += s_f ;
        }
    }
    cout << result << endl;
    return 0;
}
